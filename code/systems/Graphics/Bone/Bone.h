#ifndef GUAR_GRAPHICS_BONE_H
#define GUAR_GRAPHICS_BONE_H

//external fwd
#include <glm/fwd.hpp>
#include <memory>

//REMOVE
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>//assimp-master/code/<assimp/code/de scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing fla

namespace guar
{
	namespace GFX
	{
		class Bone
		{
			int          m_BoneIndex   ; //gpu name
			aiMatrix4x4 m_OffsetMatrix; //bone transform data

		public:
			Bone(const int& aIndex, const aiMatrix4x4 &aOffsetMatrix) :
				m_BoneIndex(aIndex),
				m_OffsetMatrix(aOffsetMatrix)
			{}

			Bone() :Bone(0, aiMatrix4x4()) //remove this
			{}

		};

	}

}

#endif