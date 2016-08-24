#ifndef GUAR_ECS_COMPONENT_H
#define GUAR_ECS_COMPONENT_H
/*
 * Component.h
 * 
*/

//stdinc
#include<iostream>
#include <memory>

namespace guar
{
	namespace ECS
	{
		class GameObject;
		class ComponentCallbackList;

		class Component
		{
			friend GameObject;
			friend std::shared_ptr<Component>;
			friend ComponentCallbackList;

			GameObject* m_GameObject;

			bool m_Ready;
		
		public: //Only GameObject can instantiate Components FIX
			Component();

			bool isReady();
			
		public:
			~Component();//call a virtual destroyfunc
			
		public: //accessors
			GameObject* getGameObject(void) { return m_GameObject; }

		protected: //Gameobject interface
			virtual void init    (void) {}; //at the scene's first update
			virtual void start   (void) {}; //CURRENTLY UNUSED
			virtual void update  (void) {}; //at main thread tick
			virtual void destroy (void) {}; //at component destruction

		};

	}

}

#endif