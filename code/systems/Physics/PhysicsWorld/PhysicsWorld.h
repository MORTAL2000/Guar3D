#ifndef GUAR_PHYSICS_PHYSICSWORLD_H
#define GUAR_PHYSICS_PHYSICSWORLD_H

//std inc
#include<vector>
#include<memory>

class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btBroadphaseInterface;
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;

namespace guar
{
	namespace PHY
	{
		class PhysicsWorld
		{
			std::shared_ptr<btDefaultCollisionConfiguration>         m_CollisionConfiguration;
			std::shared_ptr<btCollisionDispatcher>                   m_Dispatcher;
			std::shared_ptr<btBroadphaseInterface>                   m_OverlappingPairCache;
			std::shared_ptr<btSequentialImpulseConstraintSolver>     m_Solver;
			std::shared_ptr<btDiscreteDynamicsWorld>                 m_DynamicsWorld;

		public:
			std::weak_ptr<btDiscreteDynamicsWorld> getDynamicsWorld(void) { return std::weak_ptr<btDiscreteDynamicsWorld>(m_DynamicsWorld); }//remove and replace

			//void addRigidBody();

			void update(void);

			PhysicsWorld();

		};

	}

}

#endif