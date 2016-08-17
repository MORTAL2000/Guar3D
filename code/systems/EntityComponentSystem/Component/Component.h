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

		class Component
		{
			friend GameObject;
			friend std::shared_ptr<Component>;

			GameObject* m_GameObject;
		
		public: //Only GameObject can instantiate Components FIX
			Component();
			
		public:
			~Component();//call a virtual destroyfunc
			
		public: //accessors
			GameObject* getGameObject(void) { return m_GameObject; }

		private: //Gameobject interface
			virtual void init    (void) {}; //at component creation
			virtual void start   (void) {}; //at scene discretion, called only once
			virtual void update  (void) {}; //at main thread tick
			virtual void destroy (void) {}; //at component destruction

		};

	}

}

#endif