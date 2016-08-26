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
			std::vector<std::string> m_Name;
			std::vector<GFX::Bone> m_Bone;

			//std::map<std::string, GFX::Bone> m_BoneMap;


		public:
			Bone* getBone(const int aIndex) { return &m_Bone[aIndex];}

			size_t size(void) { return m_Bone.size(); }
			void push_back(const std::string& aName, const GFX::Bone &aBone) 
			{ 
				m_Name.push_back(aName); m_Bone.push_back(aBone); 

				//m_BoneMap.insert(std::map<std::string, GFX::Bone>::value_type(aName, aBone));
			
			}

		};

	}

}

#endif