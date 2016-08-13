#ifndef GUAR_PHYSICS_SCENEGRAPH_H
#define GUAR_PHYSICS_SCENEGRAPH_H

//dev inc
#include <Development\SceneGraph.h>
//std inc
#include <vector>
#include <string>
#include <memory>

namespace guar
{
	namespace ECS { class GameObject; }

	namespace PHY
	{
		class SceneGraph : public DEV::SceneGraph
		{
		public:
			void update(void);
			SceneGraph(const std::string &aName);

		};

	}

}

#endif