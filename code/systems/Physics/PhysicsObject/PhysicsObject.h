#ifndef GUAR_PHYSICS_PHYSICSOBJECT_H
#define GUAR_PHYSICS_PHYSICSOBJECT_H

//math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Quaternion\Quaternion.h>
//std inc
#include <memory>

class btCollisionShape;
class btRigidBody;
class btDiscreteDynamicsWorld;
class btTransform;

namespace guar
{
	namespace ECS { class Rigidbody; }

	namespace PHY
	{
		class PhysicsWorld;
		class SceneGraph;

		class PhysicsObject
		{
			friend SceneGraph;

			//connection to the corresponding ECS component
			std::weak_ptr<ECS::Rigidbody> m_ECSRigidbody;

			//phyics data
			std::shared_ptr<btCollisionShape> m_CollisionShape;
			std::shared_ptr<btRigidBody>      m_RigidBody;
			std::shared_ptr<btTransform>      m_Transform; //holds pos, rot
			
			//PhysicsWorld interface
			void prePhysicsStepSync (void);
			void postPhysicsStepSync(void);

		public:
			Math::Vector3 getPosition(void);
			Math::Quaternion getRotation(void);

			PhysicsObject(PhysicsWorld &aPhysicsWorld, std::weak_ptr<ECS::Rigidbody> aECSRigidbody);
			
		};

	}

}

#endif