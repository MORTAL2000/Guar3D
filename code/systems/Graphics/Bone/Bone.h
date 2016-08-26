#ifndef GUAR_GRAPHICS_BONE_H
#define GUAR_GRAPHICS_BONE_H

//external fwd
#include <glm/fwd.hpp>

namespace guar
{
	namespace GFX
	{
		class Bone
		{
			int          m_BoneIndex   ; //gpu name
			glm::mat4x4* m_OffsetMatrix; //bone transform data


		};

	}

}

#endif