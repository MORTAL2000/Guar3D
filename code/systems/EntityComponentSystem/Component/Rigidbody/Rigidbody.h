#ifndef GUAR_ECS_RIGIDBODY_H
#define GUAR_ECS_RIGIDBODY_H
/*
*
*
*/
//ecs inc
#include "../Component.h"
//math inc
#include <Math\Vector3\Vector3.h>
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

		public:
			Math::Vector3 getPosition(void);// { return m_Transform._Get()->getPosition(); }
			Math::Vector3 getRotation(void);// { return m_Transform._Get()->getRotation(); }

			void setPosition(const Math::Vector3 &aPosition);// { m_Transform._Get()->setPosition(aPosition); }


		};

	}

}


#endif