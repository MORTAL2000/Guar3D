#ifndef GUAR_DEVELOPMENT_SYSTEM_H
#define GUAR_DEVELOPMENT_SYSTEM_H

//dev inc
#include "SceneGraph.h"
//std inc
#include <memory>

struct GLFWwindow;

namespace guar
{
	class Engine;

	namespace DEV
	{
		template <class DerivedSystemType, class DerivedSceneGraphType> 
		class System
		{
			////friend class Engine;
			//
			//System() = delete; System(const System&) = delete;
			//
			////Engine interface
			//static void init     (GLFWwindow* aWindowHandle); //{ DerivedSystemType::init(GLFWwindow* aWindowHandle); }
			//static void update   (void)                     ; //{ DerivedSystemType::update();                        }
			//static void terminate(void)						; //{ DerivedSystemType::terminate();                     }
			//
			////Scenegraph related
			//static std::weak_ptr<DerivedSceneGraphType> getScene(const std::string &aName);
			//static std::weak_ptr<DerivedSceneGraphType> createScene(const std::string &aName);

		};

	}

}

#endif