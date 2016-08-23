#include "PhysicsWorld.h"
//Debug inc
#include <Debug\Debug.h>
//time inc
#include <Time\Time.h>
//External inc
#include <Bullet\btBulletDynamicsCommon.h>

using namespace guar;
using namespace PHY;

PhysicsWorld::PhysicsWorld()
{
	//Configure world parameters
	m_CollisionConfiguration = std::shared_ptr<btDefaultCollisionConfiguration>(new btDefaultCollisionConfiguration);
	m_Dispatcher = std::shared_ptr<btCollisionDispatcher>(new btCollisionDispatcher(m_CollisionConfiguration._Get()));
	m_OverlappingPairCache = std::shared_ptr<btBroadphaseInterface>(new btDbvtBroadphase());
	m_Solver = std::shared_ptr<btSequentialImpulseConstraintSolver>(new btSequentialImpulseConstraintSolver);

	//Create the bullet world
	m_DynamicsWorld = std::shared_ptr<btDiscreteDynamicsWorld>(new btDiscreteDynamicsWorld
	(
		m_Dispatcher._Get(),
		m_OverlappingPairCache._Get(),
		m_Solver._Get(),
		m_CollisionConfiguration._Get()

	));

	//set gravity direction
	//m_DynamicsWorld._Get()->setGravity(btVector3(0, -0.4f, 0));
	//m_DynamicsWorld._Get()->setGravity(btVector3(0.,-9.8f,0.));



	////////////////////////HACK//////////////////////////////////////
	//
	////collisionShapes.push_back(groundShape);
	//btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));
	//
	//btTransform groundTransform;
	//groundTransform.setIdentity();
	//groundTransform.setOrigin(btVector3(0, -55, 0));
	//
	//{
	//	btScalar mass(0.);
	//
	//	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	//	bool isDynamic = (mass != 0.f);
	//
	//	btVector3 localInertia(0, 0, 0);
	//	if (isDynamic)
	//		groundShape->calculateLocalInertia(mass, localInertia);
	//
	//	//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
	//	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	//	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
	//	btRigidBody* body = new btRigidBody(rbInfo);
	//
	//	//add the body to the dynamics world
	//	m_DynamicsWorld._Get()->addRigidBody(body);
	//}
	//
	//
	/////////////////////////////////////////////////////////

}

void PhysicsWorld::update(void)
{
	m_DynamicsWorld->stepSimulation(Time::getDeltaTime(), 20); //replace first arg with delta time
	
}

//void PhysicsWorld::addRigidBody()
//{
//
//
//}