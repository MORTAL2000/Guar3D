#ifndef GUAR_ECS_ENTITYCOMPONENTSYSTEM_H
#define GUAR_ECS_ENTITYCOMPONENTSYSTEM_H

//std inc
#include <string>
#include <memory>

namespace guar
{
	namespace ECS { class SceneGraph; }

	class EntityComponentSystem
	{
		friend class Engine;

		EntityComponentSystem() = delete; ~EntityComponentSystem() = delete;

		static void init(void);
		static void update(void);
		
		static std::weak_ptr<ECS::SceneGraph> createScene(const std::string &aName);
		static std::weak_ptr<ECS::SceneGraph> findScene(const std::string &aName);

	};

}

#endif