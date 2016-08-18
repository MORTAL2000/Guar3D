#ifndef GUAR_PHYSICS_SCENEGRAPH_H
#define GUAR_PHYSICS_SCENEGRAPH_H

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

		class SceneGraph : public DEV::SceneGraph
		{
			//friend ECS::Rigidbody;

			std::shared_ptr<PhysicsWorld>               m_World;
			std::vector<std::shared_ptr<PhysicsObject>> m_Objects;
			
		public:
			std::weak_ptr<PhysicsObject> createRigidBody(std::weak_ptr<ECS::Rigidbody>); //switch to createRigidBody, createSoftBody etc.

			void update(void);
			
			SceneGraph(const std::string &aName);

		};

	}

}

#endif