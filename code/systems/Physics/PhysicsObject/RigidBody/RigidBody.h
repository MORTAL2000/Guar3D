#ifndef GUAR_PHYSICS_RIGIDBODY_H
#define GUAR_PHYSICS_RIGIDBODY_H

//phy inc
#include "../PhysicsObject.h"
#include "../../Collider/Collider.h"
//math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Quaternion\Quaternion.h>
//std inc
#include <memory>
#include <vector>

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

		class RigidBody : public PhysicsObject
		{
			//phyics data
			std::shared_ptr<btRigidBody>      m_RigidBody;

			//PhysicsWorld interface
			void prePhysicsStepSync (void) override;
			void postPhysicsStepSync(void) override;

		public:
			RigidBody(PhysicsWorld &aPhysicsWorld, const std::vector<std::weak_ptr<PHY::Collider>> &aColliders, std::weak_ptr<ECS::Rigidbody> aECSRigidbody, const float &aMass = 0.f);

		};

	}

}

#endif