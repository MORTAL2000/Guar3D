#ifndef GUAR_ECS_SCENEGRAPHCOLLECTION_H
#define GUAR_ECS_SCENEGRAPHCOLLECTION_H

//dev inc
#include <Development\SceneGraphCollection.h>
//ecs inc
#include "../SceneGraph/SceneGraph.h"
//stdinc
#include <vector>
#include <memory>
#include <string>

namespace guar
{
	namespace ECS
	{
		class SceneGraph;

		class SceneGraphCollection : public DEV::SceneGraphCollection<ECS::SceneGraph>
		{
			

		};

	}

}

#endif