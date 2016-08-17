#ifndef GUAR_PHYSICS_PHYSICSOBJECT_H
#define GUAR_PHYSICS_PHYSICSOBJECT_H

//math inc
#include <Math\Vector3\Vector3.h>
//std inc
#include <memory>

class btCollisionShape;
class btRigidBody;
class btDiscreteDynamicsWorld;

namespace guar
{
	namespace PHY
	{
		class PhysicsWorld;

		class PhysicsObject
		{
			std::shared_ptr<btCollisionShape> m_CollisionShape;
			std::shared_ptr<btRigidBody>      m_RigidBody;
			
		public:
			Math::Vector3 getPosition(void);
			Math::Vector3 getRotation(void);

			PhysicsObject(PhysicsWorld &aPhysicsWorld);
			
		};

	}

}

#endif