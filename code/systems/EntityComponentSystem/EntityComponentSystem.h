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

		EntityComponentSystem() = delete; ~EntityComponentSystem() = delete;

		static void init(void);
		static void update(void);
		
		static ECS::SceneGraph* createScene(const std::string &aName);

	};

}

#endif