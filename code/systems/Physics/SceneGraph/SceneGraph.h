#ifndef GUAR_PHYSICS_SCENEGRAPH_H
#define GUAR_PHYSICS_SCENEGRAPH_H

//phy inc
#include "../Collider/Collider.h"
#include "../Collision/Collision.h"
//dev inc
#include <Development\SceneGraph.h>
//std inc
#include <vector>
#include <string>
#include <memory>

namespace guar
{
	namespace ECS { class Rigidbody; }
	//etc..

	namespace PHY
	{
		class PhysicsWorld;
		class PhysicsObject;
		class RigidBody;

		class SceneGraph : public DEV::SceneGraph
		{
			std::shared_ptr<PhysicsWorld>               m_World;
			std::vector<std::shared_ptr<PhysicsObject>> m_Objects;
			
		public:
			std::weak_ptr<PHY::RigidBody> createRigidBody(std::weak_ptr<ECS::Rigidbody> aECSRigidbody, std::vector<std::weak_ptr<PHY::Collider>> &aColliders, const float &aMass);
			PHY::Collision rayCast(const Math::Vector3 &aOrigin, const Math::Vector3 &aDirection, const float &aDistance);


			void update(void);
			
			SceneGraph(const std::string &aName);

		};

	}

}

#endif