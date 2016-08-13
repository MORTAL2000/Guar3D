#ifndef GUAR_GRAPHICS_SCENEGRAPH_H
#define GUAR_GRAPHICS_SCENEGRAPH_H

//dev inc
#include <Development\SceneGraph.h>
//std inc
#include <vector>
#include <string>
#include <memory>

namespace guar
{
	namespace ECS { class GameObject; }

	namespace GFX
	{
		class SceneGraph : public DEV::SceneGraph
		{
			std::vector<std::shared_ptr<class RenderLight >> m_Lights;
			std::vector<std::shared_ptr<class RenderCamera>> m_Cameras;
			std::vector<std::shared_ptr<class RenderObject>> m_Objects;

		public:
			std::weak_ptr<class RenderLight > createRenderLight  (void);
			std::weak_ptr<class RenderCamera> createRenderCamera (void);
			std::weak_ptr<class RenderObject> createRenderObject (void);

			void update(void);

			SceneGraph(const std::string &aName);

		};

	}

}

#endif