#ifndef GUAR_ECS_RIGIDBODY_H
#define GUAR_ECS_RIGIDBODY_H
/*
*
*
*/
//ecs inc
#include "../Component.h"
//std inc
#include <memory>

namespace guar
{
	namespace PHY { class PhysicsObject; }

	namespace ECS
	{
		class Transform;

		class Rigidbody : public Component
		{
			std::weak_ptr<ECS::Transform>     m_Transform;
			std::weak_ptr<PHY::PhysicsObject> m_PhysicsObject;

			//Gameobject interface
			void init  (void) override;
			void update(void) override;


		};

	}

}


#endif