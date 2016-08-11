#ifndef GUAR_ECS_SCENEGRAPHCOLLECTION_H
#define GUAR_ECS_SCENEGRAPHCOLLECTION_H

////projinc
//#include "../SceneGraph/SceneGraph.h"

//stdinc
#include <vector>
#include <memory>
#include <string>

namespace guar
{
	namespace ECS
	{
		class SceneGraph;

		class SceneGraphCollection
		{
			std::vector<guar::ECS::SceneGraph> m_Vector;

		public:
			SceneGraph* find(const std::string &aSceneGraphName);
			SceneGraph* createScene(const std::string &aName);
			void update(void);

		};

	}

}

#endif