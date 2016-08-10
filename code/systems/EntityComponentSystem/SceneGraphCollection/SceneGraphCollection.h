#ifndef GUAR_ECS_SCENEGRAPHCOLLECTION_H
#define GUAR_ECS_SCENEGRAPHCOLLECTION_H

////projinc
//#include "../SceneGraph/SceneGraph.h"

//stdinc
#include <vector>
#include <memory>

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
			void push_back(const guar::ECS::SceneGraph &aScene);
			int size(void);
			SceneGraph* back(void);
			SceneGraph* operator[](const int &i);

		};

	}

}

#endif