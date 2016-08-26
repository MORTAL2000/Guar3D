#ifndef GUAR_GRAPHICS_SKELETON_H
#define GUAR_GRAPHICS_SKELETON_H

//gfx inc
#include"../Bone/Bone.h"
//std inc
#include<map>

namespace guar
{
	namespace GFX
	{
		class Skeleton
		{
			std::map<std::string, GFX::Bone> m_BoneVector;


		};

	}

}

#endif