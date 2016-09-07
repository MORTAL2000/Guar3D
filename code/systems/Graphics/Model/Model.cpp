#include "Model.h"
//proj inc
#include "../OpenGL/OpenGL.h"
#include "../VertexFormat/VertexFormat.h"
#include <debug\Debug.h>
#include "../MeshVertex/MeshVertex.h"
#include "../Skeleton/Skeleton.h"
#include "../Bone/Bone.h"
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

using namespace guar;
using namespace GFX;


//class Node
//{
//public:
//	std::string m_Name;
//	aiMatrix4x4 m_Transform;
//
//	Node(const std::string &aName, const aiMatrix4x4 &aTransform) :
//		m_Name(aName),
//		m_Transform(aTransform)
//	{}
//
//
//};

aiNode* rootNode;


static Assimp::Importer importer;
static const aiScene*      testScene;
static aiAnimation*        testAnimation;	//Kill it with fire
static std::vector<aiBone> bones;

std::vector<aiBone>* Model::getBones()
{
	return &bones;

}

void Model::draw(const GFXuint &programHandle)
{
	animate();

	

	{
		//GLint uniformHandle = glGetUniformLocation(programHandle, "_Bones");

		//static glm::mat4x4 test[40];

		//for (size_t i = 0; i < bones.size();i++)
		//	test[i] = glm::mat4x4(1.0);

		//if (uniformHandle != -1)
		{
			

			//for(size_t i = 0; i < bones.size(); i++)
			//{ 
			//	test[i][0][0] = bones[i].mOffsetMatrix.a1;
			//	test[i][0][1] = bones[i].mOffsetMatrix.a2;
			//	test[i][0][2] = bones[i].mOffsetMatrix.a3;
			//	test[i][0][3] = bones[i].mOffsetMatrix.a4;
			//
			//	test[i][1][0] = bones[i].mOffsetMatrix.b1;
			//	test[i][1][1] = bones[i].mOffsetMatrix.b2;
			//	test[i][1][2] = bones[i].mOffsetMatrix.b3;
			//	test[i][1][3] = bones[i].mOffsetMatrix.b4;
			//
			//	test[i][2][0] = bones[i].mOffsetMatrix.c1;
			//	test[i][2][1] = bones[i].mOffsetMatrix.c2;
			//	test[i][2][2] = bones[i].mOffsetMatrix.c3;
			//	test[i][2][3] = bones[i].mOffsetMatrix.c4;
			//
			//	test[i][3][0] = bones[i].mOffsetMatrix.d1;
			//	test[i][3][1] = bones[i].mOffsetMatrix.d2;
			//	test[i][3][2] = bones[i].mOffsetMatrix.d3;
			//	test[i][3][3] = bones[i].mOffsetMatrix.d4;
			//
			//}

			//for (size_t i = 0; i < 40; i++)
			//{
			//	test[i] = glm::mat4x4();
			//	test[i] = glm::translate<>(test[i],glm::vec3(0, 0, 0));
			//
			//}
			
			//Debug::log("asdfasdfasdf\n");
			
			//float* arrayOfBoneMatricies = &test[0][0][0];
			//glUniformMatrix4fv(uniformHandle, 40, GL_FALSE, arrayOfBoneMatricies);

		}
	
	}

	//{
	//	GLint uniformHandle = glGetUniformLocation(programHandle, "tester");
	//
	//	if (uniformHandle != -1)
	//	{
	//		static float tester = 0;
	//		tester += 0.1;
	//		glUniform1f(uniformHandle, cos(tester)*100.);
	//
	//	}
	//
	//}

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

//
// Node functions
//
void logNodeHierarchy(aiNode* currentNode) //DONE
{
	//Calculate depth
	aiNode* parentPointer = currentNode;
	int parentCounter = 0;
	aiMatrix4x4 parentTransformProduct = parentPointer->mTransformation;
	while (parentPointer->mParent != NULL)
	{
		parentCounter++;
		parentPointer = parentPointer->mParent;

	}

	//report who i am
	Debug::log("Node name:",currentNode->mName.C_Str(), " Depth: ",parentCounter, "\n");
	
	//Go deeper
	for (size_t i = 0; i < currentNode->mNumChildren;i++)
	{
		logNodeHierarchy(currentNode->mChildren[i]);

	}
	
}

//void copyNodeHierarchy(aiNode* currentNode, aiNode* aNewParent = 0)
//{
//	aiNode* newCurrent = new aiNode;
//	*newCurrent = *currentNode;
//
//	if (currentNode->mParent == NULL)
//		rootNode = newCurrent;
//	else
//	{ 
//		aNewParent->mChildren[0] = newCurrent;
//	
//	}
//
//	//Go deeper
//	for (size_t i = 0; i < currentNode->mNumChildren;i++)
//	{
//		copyNodeHierarchy(currentNode->mChildren[i], newCurrent);
//
//	}
//	
//}

void updateNodeHierarchy(aiNode* currentNode, aiAnimation* animation) //MAY BE GOOD, MUST TEST
{
	for (size_t i = 0; i < animation->mNumChannels; i++)
		if (currentNode->mName == animation->mChannels[i]->mNodeName)
		{
			aiVector3D   position;
			aiQuaternion rotation;
			aiVector3D   scaling ;

			if (animation->mChannels[i]->mNumPositionKeys > 0)
				position = animation->mChannels[i]->mPositionKeys[0].mValue;

			if (animation->mChannels[i]->mNumRotationKeys > 0)
				rotation = animation->mChannels[i]->mRotationKeys[0].mValue;

			if (animation->mChannels[i]->mNumScalingKeys > 0)
				scaling = animation->mChannels[i]->mScalingKeys[0].mValue;

			currentNode->mTransformation *= aiMatrix4x4(scaling,rotation,position);

		}

	// continue traversing the nodes...
	for (size_t i = 0; i < currentNode->mNumChildren;i++)
		updateNodeHierarchy(currentNode->mChildren[i], animation);

}

void updateBoneTransforms(aiNode* currentNode, std::vector<aiBone> &ioBones) //MAY BE GOOD, MUST TEST
{
	// calculate final modelspace transform
	aiMatrix4x4 myTransform;
	aiNode* parentPointer = currentNode->mParent;
	int parentCounter = 0;

	while (parentPointer != NULL)
	{
		myTransform *= parentPointer->mTransformation;
		parentCounter++;
		parentPointer = parentPointer->mParent;
		
	}

	// update modelspace transform data on bone
	for (size_t i = 0; i < ioBones.size(); i++)
		if (ioBones[i].mName == currentNode->mName)
			ioBones[i].mOffsetMatrix = myTransform;

	// continue traversing the nodes...
	for (size_t i = 0; i < currentNode->mNumChildren;i++)
		updateBoneTransforms(currentNode->mChildren[i], ioBones);

}

void megaTestUpdateSkeleton(aiNode* currentNode, aiAnimation* animation, std::vector<aiBone> &ioBones) //MAY BE GOOD, MUST TEST
{
	static size_t key = 0; //hardcoded key
	
	for (size_t i = 0; i < animation->mNumChannels; i++)
		if (currentNode->mName == animation->mChannels[i]->mNodeName)
		{
			//get the animation deltas for this node
			aiVector3D   position;
			aiQuaternion rotation;
			aiVector3D   scaling;

			position = aiVector3D(0, 200, 0);
			rotation = aiQuaternion(1, 0, 0, 0);
			scaling = aiVector3D(1, 1, 1);

			if (animation->mChannels[i]->mNumPositionKeys > 0)
				position = animation->mChannels[i]->mPositionKeys[key].mValue;
						
			if (animation->mChannels[i]->mNumRotationKeys > 0)
				rotation = animation->mChannels[i]->mRotationKeys[key].mValue;
			
			if (animation->mChannels[i]->mNumScalingKeys > 0)
				scaling = animation->mChannels[i]->mScalingKeys[key].mValue;

			//update the node
			currentNode->mTransformation = aiMatrix4x4(scaling, rotation, position);

		}
	
	// continue traversing the nodes...
	for (size_t i = 0; i < currentNode->mNumChildren;i++)
		megaTestUpdateSkeleton(currentNode->mChildren[i], animation, ioBones);

	

}

void megaTestUpdateBone(aiBone &ioBone)
{
	//find the bone in the node hierarchy
	aiNode* myNode = rootNode->FindNode(ioBone.mName);

	if (!myNode)
		return;

	//calculate modelspace transform
	aiNode*     currentNode         = myNode;
	aiMatrix4x4 modelSpaceTransform = currentNode->mTransformation;

	while (currentNode->mParent != 0)
	{
		currentNode = currentNode->mParent;
		modelSpaceTransform *= currentNode->mTransformation;

	}

	//apply transform to the bone
	ioBone.mOffsetMatrix = modelSpaceTransform;


}

void megaTestUpdateBones()
{
	for (size_t i = 0; i < bones.size(); i++)
		megaTestUpdateBone(bones[i]);

}

void Model::animate(void)
{
	//
	// Calculate animation offset
	//
	float AnimationTime;
	{
		//TIME ARGUMENT
		static float TimeInSeconds = 0;
		TimeInSeconds += 0.1;
		//CALCULATE TIME OFFSET
		float TicksPerSecond = 25.;
		if (testAnimation->mTicksPerSecond != 0)
			TicksPerSecond = testAnimation->mTicksPerSecond;

		float TimeInTicks = TimeInSeconds * TicksPerSecond;

		AnimationTime = fmod(TimeInTicks, testAnimation->mDuration);

	}

	//
	// interpolate transforms etc.
	//
	//updateSkelly(AnimationTime)
	{
		//updateNodeHierarchy(rootNode,testAnimation);

	}

	//
	// update transforms
	//
	{
		megaTestUpdateSkeleton(rootNode, testAnimation, bones);
		megaTestUpdateBones();


	}

	

}

Model::Model(const std::string &aFileName, const std::string &aMeshName) : Model(aFileName, loadMeshFromFile(aFileName, aMeshName))
{}

Vertex::Data Model::loadMeshFromFile(const std::string &aFileName, const std::string &aMeshName)
{
	Debug::alert("loading model ", aFileName, "\n");

	//create a context on the file
	//Assimp::Importer importer;

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
	Debug::alert("Loading mesh: ", mesh->mName.C_Str(), "'s vertex data", "\n");
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

		aiBone** fbones = mesh->mBones;
		aiBone* currentBone = 0;
		for (int i = 0; i < mesh->mNumBones; i++)
		{
			currentBone = fbones[i];
			
			currentBone->mName.C_Str();
						
			//m_Skeleton.push_back
			//(
			//	currentBone->mName.C_Str(), 
			//	GFX::Bone(i,currentBone->mOffsetMatrix)
			//
			//);

			bones.push_back(aiBone(*currentBone));
			
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

					//Debug::log("BONEDATA IS COMING: ", i);

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
		Debug::alert("Reading animation names in file\n");

		for (size_t i = 0; i < scene->mNumAnimations; i++) //read the name of all the animations
		{
			Debug::log("Animation name: ", scene->mAnimations[i]->mName.C_Str(), "\n");

		}

		testAnimation = scene->mAnimations[0];

	}

	
	aiNode* rootNodeSource = scene->mRootNode;
	
	rootNode = rootNodeSource;
	
	logNodeHierarchy(rootNode);
	//copyNodeHierarchy(rootNodeSource,0);



	Debug::log(testAnimation->mNumChannels, "\n");
	for (size_t i = 0; i < testAnimation->mNumChannels; i++) //read the name of all the animations
	{
		Debug::log("TestAnimation channel names: ",testAnimation->mChannels[i]->mNodeName.C_Str(), "\n");
	
	}
	
	return vertexes;

}