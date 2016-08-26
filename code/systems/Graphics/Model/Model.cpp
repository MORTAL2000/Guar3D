#include "Model.h"
//proj inc
#include "../OpenGL/OpenGL.h"
#include "../VertexFormat/VertexFormat.h"
#include <debug\Debug.h>
#include "../MeshVertex/MeshVertex.h"
//std inc
#include <stdio.h>
#include <vector>
//implementation "assimp" inc
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>//assimp-master/code/<assimp/code/de scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing fla
//implementation "Ozz" inc
#include <ozz/animation/offline/raw_skeleton.h>
#include <ozz/animation/offline/skeleton_builder.h>
#include <ozz/animation/runtime/skeleton.h>

using namespace guar;
using namespace GFX;

void Model::draw(const GFXuint &programHandle)
{
	animate();

    Vertex::EnableAttributes(programHandle, m_VertexBufferHandle);
    glDrawArrays( GL_TRIANGLES, 0, m_VertexCount );
    
}

void Model::animate(void)
{


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

Model::Model(const std::string &aFileName, const std::string &aMeshName) : Model(aFileName, loadMeshFromFile(aFileName, aMeshName))
{}

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

	//std::vector<MeshVertex> meshVertexes;
	Vertex::Data vertexes;

	if (!scene)
	{
		Debug::log("Error Importing Asset: ", aFileName, ". The scene is null", "\n");
		return vertexes;

	}

	//read the first mesh HARDCODE, THIS FUNC SHOULD REALLY BE REFACTORED OUT OF GFX::MODEL
	aiMesh *mesh = scene->mMeshes[0];

	if (!mesh)
	{
		Debug::log("Error Importing Asset: ", aFileName, ". mesh[0] is null", "\n");
		return vertexes;

	}
	
	///////This targets a specific sub model. Was not used.
	//if (!aMeshName.empty())
	//	for (int i = 0; i < scene->mNumMeshes; i++)
	//		if (scene->mMeshes[i]->mName.C_Str() == aMeshName)
	//			mesh = scene->mMeshes[i];

	//
	// COPY THE MESH
	//
	Debug::log("Loading mesh: ", mesh->mName.C_Str(), "'s vertex data", "\n");
	const int numFaces = mesh->mNumFaces;
	m_VertexCount = numFaces * 3;
	
	for (unsigned int i = 0; i < numFaces; i++)
	{
		const aiFace& face = mesh->mFaces[i];

		for (int j = 0; j < 3; j++)
		{						// ((a < b) ? a : b)
			aiVector3D pos       = (mesh->HasPositions())             ?  mesh->mVertices        [face.mIndices[j]] : aiVector3D();
			aiVector3D uv        = (mesh->HasTextureCoords(0))        ?  mesh->mTextureCoords[0][face.mIndices[j]] : aiVector3D();
			aiVector3D normal    = (mesh->HasNormals())               ?  mesh->mNormals         [face.mIndices[j]] : aiVector3D();
			aiVector3D tangent   = (mesh->HasTangentsAndBitangents()) ?  mesh->mTangents        [face.mIndices[j]] : aiVector3D();
			aiVector3D bitangent = (mesh->HasTangentsAndBitangents()) ?  mesh->mBitangents      [face.mIndices[j]] : aiVector3D();

			GFX::Vertex::Format vertdata =
				Vertex::create
				(
					pos      .x, pos      .y, pos      .z,
					uv       .x, uv       .y,		   
					normal   .x, normal   .y, normal   .z,
					tangent  .x, tangent  .y, tangent  .z,
					bitangent.x, bitangent.y, bitangent.z

				);

			vertexes.push_back
			(
				vertdata
			
			); // 1--0

			/////HACK: STORING DATA IN CPUSIDE BUFFER FOR CPU SIDE ANIM
			//meshVertexes.push_back(MeshVertex());
			//meshVertexes.back().setGPUVertexData(vertdata);

		}

	}

	//
	// COPY THE SKELETON
	//
	Debug::log("bone count: ",mesh->mNumBones, "\n");
	if (mesh->HasBones())
	{
		Debug::log("Loading mesh: ", mesh->mName.C_Str(), "'s skeleton data", "\n");

		// Creates a RawSkeleton.
		ozz::animation::offline::RawSkeleton raw_skeleton;

		//create joints...
		aiBone** bones = mesh->mBones;
		aiBone* currentBone = 0;
		for (int i = 0; i < mesh->mNumBones; i++)
		{
			currentBone = bones[i];
			
			//get name
			std::string name = (currentBone->mName).C_Str();
			Debug::log("Bone name: ",name, "\n");

			//get bone transform matrix
			currentBone->mOffsetMatrix;

			//Iterate the array of affected vertexes
			for (int j = 0; j < currentBone->mNumWeights; j++)
			{
				//PUSH BONE DATA INTO VERTEX DATA
				if (vertexes.get(currentBone->mWeights[j].mVertexId)->bone1I == -1)
				{
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone1I = i; //index of bone
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone1W = currentBone->mWeights[j].mWeight; //weight of bone

				}
				else if (vertexes.get(currentBone->mWeights[j].mVertexId)->bone2I == -1)
				{
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone2I = i; //index of bone
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone2W = currentBone->mWeights[j].mWeight; //weight of bone

				}
				else if (vertexes.get(currentBone->mWeights[j].mVertexId)->bone3I == -1)
				{
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone3I = i; //index of bone
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone3W = currentBone->mWeights[j].mWeight; //weight of bone

				}
				else if (vertexes.get(currentBone->mWeights[j].mVertexId)->bone4I == -1)
				{
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone4I = i; //index of bone
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone4W = currentBone->mWeights[j].mWeight; //weight of bone

				}
				else if (vertexes.get(currentBone->mWeights[j].mVertexId)->bone5I == -1)
				{
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone5I = i; //index of bone
					vertexes.get(currentBone->mWeights[j].mVertexId)->bone5W = currentBone->mWeights[j].mWeight; //weight of bone

				}
				else
				{
					Debug::log("too many weights\n");
					assert(0);
				}

			}
			
		}
		
	}

	//
	// COPY ANIMATIONS
	//
	// todo

	
	
	
	//int boneinfluencecount = 0;
	//
	//for (int i = 0; i < vertexes.size(); i++)
	//	if (vertexes[i] > boneinfluencecount)
	//		boneinfluencecount = meshVertexes[i].getBoneDataSize();
	//
	//Debug::log("NUMBER OF INFLUENCING BONES IS: ", boneinfluencecount, "\n");
	//if (mesh->HasBones())
	//{
	//	for (int i = 0; i < vertexes.size(); i++)
	//	{
	//		if (vertexes.get(i)->bone1I != -1)
	//			Debug::log("vertex no: ", i, ", ", vertexes.get(i)->bone1I, "\n");
	//
	//	}
	//
	//	Debug::log("bone number: ", mesh->mNumBones,"\n");
	//
	//}
	
	//push data out
	//m_CPUVertexBuffer = meshVertexes;

	return vertexes;

}