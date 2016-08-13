#ifndef GUAR_ENGINE_H
#define GUAR_ENGINE_H
/*
 *  Engine.h
 *  
 *  
 */
//stdinc
#include <string>
#include <memory>

namespace guar
{
	namespace ECS { class SceneGraph; }

    class Engine final
    {
		Engine() = delete; ~Engine() = delete;

		//Private methods
		static void init(void);  //consider refactoring these..
		static void terminate(void);

	public: //Public interface
		static void mainInit(void);
		static void mainLoop(void);

		static std::weak_ptr<guar::ECS::SceneGraph> createScene(const std::string &aName);
		static std::weak_ptr<guar::ECS::SceneGraph> findScene(const std::string &aName);

    };
    
};

#endif