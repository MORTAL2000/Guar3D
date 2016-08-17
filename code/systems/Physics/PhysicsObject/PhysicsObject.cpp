#include "PhysicsObject.h"
//physics inc
#include "../PhysicsWorld/PhysicsWorld.h"
//External inc
#include <Bullet\btBulletDynamicsCommon.h>

using namespace guar;
using namespace PHY;

PhysicsObject::PhysicsObject(PhysicsWorld &aPhysicsWorld) :
	m_CollisionShape(0),
	m_RigidBody(0)
{

	//create a dynamic rigidbody
	
	//btCollisionShape* colShape = new btBoxShape(btVector3(1,1,1));
	btCollisionShape* colShape = new btSphereShape(btScalar(1.));
	//m_CollisionShapes.push_back(std::shared_ptr<btCollisionShape>(colShape)); //this seems to be a memory management strategy, i will be using a different approach

	/// Create Dynamic Objects
	btTransform startTransform;
	startTransform.setIdentity();

	btScalar	mass(1.f);

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		colShape->calculateLocalInertia(mass, localInertia);

	startTransform.setOrigin(btVector3(0, 50, 0));

	//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);
	




	//add to world
	aPhysicsWorld.getDynamicsWorld()._Get()->addRigidBody(body);
	
	//push data to world and object
	m_CollisionShape = std::shared_ptr<btCollisionShape>(colShape);
	m_RigidBody      = std::shared_ptr<btRigidBody>     (body);

	
	
}

Math::Vector3 PhysicsObject::getPosition(void)
{
	btTransform trans;
	m_RigidBody._Get()->getMotionState()->getWorldTransform(trans);

	return Math::Vector3(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ() );

}

//Math::Vector3 PhysicsObject::getRotation(void)
//{
//
//
//}