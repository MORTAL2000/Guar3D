#include "Model.h"

//proj inc
#include "../OpenGL/OpenGL.h"
#include "../VertexFormat/VertexFormat.h"
#include <debug\Debug.h>

//std inc
//#include <iostream>
#include <stdio.h>
#include <vector>

//lib inc
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>//assimp-master/code/<assimp/code/de scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing fla

using namespace guar;
using namespace GFX;

void Model::draw(const GFXuint &programHandle)
{
    Vertex::EnableAttributes(programHandle, m_VertexBufferHandle);
    glDrawArrays( GL_TRIANGLES, 0, m_VertexCount );
    
}

Model::Model(const std::string &aName, Vertex::Data aVertexData)
{
	m_Name = aName;

    //Create buffer
    GLuint vbo = 0;
    glGenBuffers (1, &vbo);
    
    m_VertexBufferHandle = vbo;
    m_VertexCount = aVertexData.size();
    
    glBindBuffer (GL_ARRAY_BUFFER, vbo);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex::Format)*aVertexData.size(), aVertexData.toArray(), GL_STATIC_DRAW);
    glBindBuffer( GL_ARRAY_BUFFER,0);

	
    
}

//Model::Model(const std::string &aFileName) : Model(aFileName, aFileName) {}

Model::Model(const std::string &aFileName, const std::string &aMeshName) : Model(aFileName,loadMeshFromFile(aFileName, aMeshName)) {}

Vertex::Data Model::loadMeshFromFile(const std::string &aFileName, const std::string &aMeshName)
{
	Debug::log("loading model ", aFileName, "\n");

	//create a context on the file
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile
	(
		aFileName, 
		aiProcessPreset_TargetRealtime_Fast |
		aiProcess_FixInfacingNormals		|
		aiProcess_GenNormals				|
		aiProcess_CalcTangentSpace			
	
	);

	Vertex::Data vertexes;

	if (!scene)
		Debug::log("Error Importing Asset: ", aFileName, "\n");
	else
	{
		//read data
		aiMesh *mesh = scene->mMeshes[0];
		
		if (!aMeshName.empty())
			for (int i = 0; i < scene->mNumMeshes; i++)
				if (scene->mMeshes[i]->mName.C_Str() == aMeshName)
					mesh = scene->mMeshes[i];

		//Check if vertex data is missing and needs to be generated (normals, tangents, bitangents)
		//if (!mesh->HasNormals())
		//{
		//	std::cout << aFileName << ": NO NORMALS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'\n";
		//	scene = importer.ApplyPostProcessing(aiProcess_GenNormals);

		//}

		const int numFaces = mesh->mNumFaces;
		m_VertexCount = numFaces * 3;

		Debug::log("Loading mesh: ", mesh->mName.C_Str(), "\n");

		for (unsigned int i = 0; i < numFaces; i++)
		{
			const aiFace& face = mesh->mFaces[i];

			for (int j = 0; j < 3; j++)
			{
				aiVector3D pos       = mesh->mVertices        [face.mIndices[j]];
				aiVector3D uv        = mesh->mTextureCoords[0][face.mIndices[j]];
				aiVector3D normal    = mesh->mNormals         [face.mIndices[j]];
				aiVector3D tangent   = mesh->mTangents        [face.mIndices[j]];
				aiVector3D bitangent = mesh->mBitangents      [face.mIndices[j]];

				vertexes.push_back
				(
					Vertex::create
					(
						pos.x, pos.y, pos.z, 
						uv.x, uv.y, 
						normal.x, normal.y, normal.z,
						tangent.x, tangent.y, tangent.z,
						bitangent.x, bitangent.y, bitangent.z
					
					)
				
				); // 1--0

			}

		}
	
	}

	return vertexes;

}