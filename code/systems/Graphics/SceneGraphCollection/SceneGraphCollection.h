#ifndef GUAR_GRAPHICS_SCENEGRAPHCOLLECTION_H
#define GUAR_GRAPHICS_SCENEGRAPHCOLLECTION_H

//std inc
#include <vector>
#include <memory>
#include <string>

namespace guar
{
	namespace GFX
	{
		class SceneGraph;

		class SceneGraphCollection
		{
			std::vector<std::shared_ptr<SceneGraph>> m_Scenes;

		public:
			void update(void);

			std::weak_ptr<SceneGraph> createScene(const std::string &aName);
			std::weak_ptr<SceneGraph> findScene(const std::string &aName);

		};

	}

}

#endif