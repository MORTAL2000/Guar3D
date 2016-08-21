#ifndef GUAR_ECS_ENTITYCOMPONENTSYSTEM_H
#define GUAR_ECS_ENTITYCOMPONENTSYSTEM_H

//std inc
#include <string>
#include <memory>

struct GLFWwindow;

namespace guar
{
	namespace ECS { class SceneGraph; }

	class EntityComponentSystem
	{
		friend class Engine;
		//friend class GameObject;
		//EntityComponentSystem();
		EntityComponentSystem() = delete; ~EntityComponentSystem() = delete;

		//Engine interface
		static void init(GLFWwindow* aWindowHandle);
		static void update(void);
		static void terminate(void);
		
		//Scenegraph interface
		static std::weak_ptr<ECS::SceneGraph> createScene(const std::string &aName);
		static std::weak_ptr<ECS::SceneGraph> findScene(const std::string &aName);

	};

}

#endif