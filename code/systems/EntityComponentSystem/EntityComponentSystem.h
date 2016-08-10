#ifndef GUAR_ECS_ENTITYCOMPONENTSYSTEM_H
#define GUAR_ECS_ENTITYCOMPONENTSYSTEM_H

//std inc
#include <string>

namespace guar
{
	namespace ECS { class SceneGraph; }

	class EntityComponentSystem
	{
		friend class Engine;

		static ECS::SceneGraph* createScene(const std::string &aName);

	public:
		static void init(void);
		static void update(void);

	};

}

#endif