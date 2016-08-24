#ifndef GUAR_ECS_PHYSICSBODY_H
#define GUAR_ECS_PHYSICSBODY_H

//ecs inc
#include "../Component.h"
//math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Quaternion\Quaternion.h>
//std inc
#include <memory>

namespace guar
{
	namespace PHY { class PhysicsObject; }
	
	namespace ECS
	{
		class Transform;

		class PhysicsBody : public Component
		{
		protected:
			std::weak_ptr<ECS::Transform>     m_Transform     ;
			std::weak_ptr<PHY::PhysicsObject> m_PhysicsObject ;

			//Gameobject interface
			void init(const std::weak_ptr<PHY::PhysicsObject> &aPhysicsObject);
			void update(void) override;

		public:
			Math::Vector3    getPosition(void);
			Math::Quaternion getRotation(void);

			void setPosition(const Math::Vector3 &aPosition);

		};

	}

}

#endif