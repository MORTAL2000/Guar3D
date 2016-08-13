#ifndef GUAR_PHYSICS_PHYSICS_H
#define GUAR_PHYSICS_PHYSICS_H

//std inc
#include <string>
#include <memory>

struct GLFWwindow;
namespace guar { namespace ECS { class SceneGraph; } }

namespace guar
{
	namespace PHY { class SceneGraph; }

	class Physics final
	{
		friend class Engine;
		friend ECS::SceneGraph;
		Physics() = delete; ~Physics() = delete;

		//Engine interface
		static void init(GLFWwindow* aWindowHandle);
		static void update(void);
		static void terminate(void);

		//Scenegraph interface
		static std::weak_ptr<PHY::SceneGraph> getScene(const std::string &aName);
		static std::weak_ptr<PHY::SceneGraph> createScene(const std::string &aName);

	public: //Game programmer interface


	};

}

#endif