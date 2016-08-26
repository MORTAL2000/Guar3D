#ifndef GUAR_GRAPHICS_MESHVERTEX_H
#define GUAR_GRAPHICS_MESHVERTEX_H

//GFX::Vertex (a namespace) and GFX::MeshVertex are badly named. rename for legibility

#include "../VertexFormat/VertexFormat.h"

#include <vector>
#include <tuple>

namespace guar
{
	namespace GFX
	{
		class MeshVertex
		{
			GFX::Vertex::Format                          m_GPUVertexData;
			std::vector <std::tuple<std::string, float>> m_BoneData;

		public:
			void setGPUVertexData(const GFX::Vertex::Format& aVertexFormat) { m_GPUVertexData = aVertexFormat; }
			void setCPUBoneData  (const std::string &aBoneName, const float &aBoneWeight){ m_BoneData.push_back(std::tuple<std::string, float>(aBoneName,aBoneWeight)); }

			size_t getBoneDataSize(void) { return m_BoneData.size(); }

		};

	}

}

#endif