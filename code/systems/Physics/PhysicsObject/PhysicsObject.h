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
	namespace ECS { class PhysicsBody; }

	namespace PHY
	{
		class PhysicsWorld;
		class SceneGraph;

		class PhysicsObject
		{
			friend SceneGraph;

		protected:
			//connection to the corresponding ECS component
			std::weak_ptr<ECS::PhysicsBody> m_ECSPhysicsBody;

			//phyics data
			std::shared_ptr<btCollisionShape> m_CollisionShape;
			std::shared_ptr<btTransform>      m_Transform; //holds pos, rot
			
			//PhysicsWorld interface
			virtual void prePhysicsStepSync (void) = 0;
			virtual void postPhysicsStepSync(void) = 0;

		public:
			std::weak_ptr<ECS::PhysicsBody> getECSPhysicsBody(void);

			virtual Math::Vector3    getPosition(void);
			virtual Math::Quaternion getRotation(void);

			void setPosition(const Math::Vector3    &aPosition);
			void setRotation(const Math::Quaternion &aRotation);

			PhysicsObject(PhysicsWorld &aPhysicsWorld, std::weak_ptr<ECS::PhysicsBody> aECSPhysicsBody);
			
		};

	}

}

#endif