#include "Model.h"
//proj inc
#include "../OpenGL/OpenGL.h"
#include "../VertexFormat/VertexFormat.h"
#include <debug\Debug.h>
#include "../MeshVertex/MeshVertex.h"
#include "../Skeleton/Skeleton.h"
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
//glm
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtx/quaternion.hpp>

#include "ogldev_math_3d.h"


using namespace guar;
using namespace GFX;

static const aiScene* testScene;
static aiAnimation* testAnimation;	//Kill it with fire

//void CalcInterpolatedScaling(aiVector3D& Out, float AnimationTime, const aiNodeAnim* pNodeAnim)
//{
//	if (pNodeAnim->mNumScalingKeys == 1) {
//		Out = pNodeAnim->mScalingKeys[0].mValue;
//		return;
//	}
//
//	uint ScalingIndex = FindScaling(AnimationTime, pNodeAnim);
//	uint NextScalingIndex = (ScalingIndex + 1);
//	assert(NextScalingIndex < pNodeAnim->mNumScalingKeys);
//	float DeltaTime = (float)(pNodeAnim->mScalingKeys[NextScalingIndex].mTime - pNodeAnim->mScalingKeys[ScalingIndex].mTime);
//	float Factor = (AnimationTime - (float)pNodeAnim->mScalingKeys[ScalingIndex].mTime) / DeltaTime;
//	assert(Factor >= 0.0f && Factor <= 1.0f);
//	const aiVector3D& Start = pNodeAnim->mScalingKeys[ScalingIndex].mValue;
//	const aiVector3D& End = pNodeAnim->mScalingKeys[NextScalingIndex].mValue;
//	aiVector3D Delta = End - Start;
//	Out = Start + Factor * Delta;
//}
//
//
//void ReadNodeHeirarchy(float AnimationTime, const aiNode* pNode, const Matrix4f& ParentTransform)
//{
//	std::string NodeName(pNode->mName.data);
//
//	const aiAnimation* pAnimation = testScene->mAnimations[0];
//
//	Matrix4f NodeTransformation(pNode->mTransformation);
//
//	const aiNodeAnim* pNodeAnim = FindNodeAnim(pAnimation, NodeName);
//
//	if (pNodeAnim) {
//		// Interpolate scaling and generate scaling transformation matrix
//		aiVector3D Scaling;
//		CalcInterpolatedScaling(Scaling, AnimationTime, pNodeAnim);
//		Matrix4f ScalingM;
//		ScalingM.InitScaleTransform(Scaling.x, Scaling.y, Scaling.z);
//
//		// Interpolate rotation and generate rotation transformation matrix
//		aiQuaternion RotationQ;
//		CalcInterpolatedRotation(RotationQ, AnimationTime, pNodeAnim);
//		Matrix4f RotationM = Matrix4f(RotationQ.GetMatrix());
//
//		// Interpolate translation and generate translation transformation matrix
//		aiVector3D Translation;
//		CalcInterpolatedPosition(Translation, AnimationTime, pNodeAnim);
//		Matrix4f TranslationM;
//		TranslationM.InitTranslationTransform(Translation.x, Translation.y, Translation.z);
//
//		// Combine the above transformations
//		NodeTransformation = TranslationM * RotationM * ScalingM;
//	}
//
//	Matrix4f GlobalTransformation = ParentTransform * NodeTransformation;
//
//	if (m_BoneMapping.find(NodeName) != m_BoneMapping.end()) {
//		uint BoneIndex = m_BoneMapping[NodeName];
//		m_BoneInfo[BoneIndex].FinalTransformation = m_GlobalInverseTransform * GlobalTransformation *
//			m_BoneInfo[BoneIndex].BoneOffset;
//	}
//
//	for (uint i = 0; i < pNode->mNumChildren; i++) {
//		ReadNodeHeirarchy(AnimationTime, pNode->mChildren[i], GlobalTransformation);
//	}
//}


void Model::animate(void)
{
	std::vector<Matrix4f> Transforms;

	//Debug::log("animating\n");
	
	Matrix4f Identity;
	Identity.InitIdentity();
	
	
	//TIME ARGUMENT
	static float TimeInSeconds = 0;
	TimeInSeconds += 0.1;

	//CALCULATE TIME OFFSET
	float TicksPerSecond = 25.;
	if (testAnimation->mTicksPerSecond != 0)
		TicksPerSecond = testAnimation->mTicksPerSecond;
	float TimeInTicks = TimeInSeconds * TicksPerSecond;
	float AnimationTime = fmod(TimeInTicks, testAnimation->mDuration);
	
	//ReadNodeHeirarchy(AnimationTime, testScene->mRootNode, Identity);
	
	Transforms.resize(m_Skeleton.size());
	
	for (unsigned int i = 0; i < m_Skeleton.size(); i++)
	{
		//Transforms[i] = m_Skeleton.getBone(i).FinalTransformation;
	
	}

}

void Model::draw(const GFXuint &programHandle)
{
	animate();

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

	testScene = scene;

	//read the first mesh HARDCODE, THIS FUNC SHOULD REALLY BE REFACTORED OUT OF GFX::MODEL
	aiMesh *mesh = scene->mMeshes[0];

	if (!mesh)
	{
		Debug::log("Error Importing Asset: ", aFileName, ". mesh[0] is null", "\n");
		return vertexes;

	}

	//
	// COPY THE VERTEX ATTRIBUTE DATA
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
			
			);

		}

	}

	//
	// COPY BONE DATA TO SKELETON AND PUSH WEIGHT DATA INTO VERTS (since animation is GPU based for this engine)
	//
	Debug::log("bone count: ",mesh->mNumBones, "\n");
	if (mesh->HasBones())
	{
		Debug::log("Loading mesh: ", mesh->mName.C_Str(), "'s skeleton data", "\n");

		aiBone** bones = mesh->mBones;
		aiBone* currentBone = 0;
		for (int i = 0; i < mesh->mNumBones; i++)
		{
			currentBone = bones[i];
			
			currentBone->mName.C_Str();
						
			m_Skeleton.push_back
			(
				currentBone->mName.C_Str(), 
				GFX::Bone(i,currentBone->mOffsetMatrix)
			
			);
			
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
	if (scene->HasAnimations())
	{
		testAnimation = scene->mAnimations[0];

	}
	
	return vertexes;

}