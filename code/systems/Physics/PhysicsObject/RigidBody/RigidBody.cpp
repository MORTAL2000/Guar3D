#include "RigidBody.h"
//physics inc
#include "../../PhysicsWorld/PhysicsWorld.h"
//ecs inc
#include <EntityComponentSystem\Component\PhysicsBody\Rigidbody\Rigidbody.h>
//External inc
#include <Bullet\btBulletDynamicsCommon.h>

#include <Debug\Debug.h>
using namespace guar;
using namespace PHY;

RigidBody::RigidBody(PhysicsWorld &aPhysicsWorld, const std::vector<std::weak_ptr<PHY::Collider>> &aColliders, std::weak_ptr<ECS::Rigidbody> aECSRigidbody, const float &aMass) :
	PhysicsObject(aPhysicsWorld, aECSRigidbody)
{
	//m_ECSRigidbody = aECSRigidbody;

	//create the compound shape
	btCompoundShape* compoundShape = new btCompoundShape(true, 1);
	//push back data to shape
	for(int i = 0; i < aColliders.size(); i++)//foreach PHY::Collider
	{
		btTransform transform;
		transform.setIdentity();
		
		btCollisionShape* box = aColliders[i]._Get()->getCollisionShape()._Get();
		Debug::log(((btBoxShape*)box)->getHalfExtentsWithMargin().x(), "\n");
		
		//transform.setRotation(btQuaternion(x, y, z));
		//transform.setOrigin(btVector3(x, y, z));
		compoundShape->addChildShape(transform, box);
	
	}

	btCollisionShape* colShape = compoundShape;//new btSphereShape(btScalar(1.f));

	// Create Dynamic Objects
	m_Transform._Get()->setIdentity();

	btScalar	mass(1.f);
	mass = aMass;

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		colShape->calculateLocalInertia(mass, localInertia);

	m_Transform._Get()->setOrigin(btVector3(0, 0, 0));

	//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState* myMotionState = new btDefaultMotionState(*m_Transform._Get());
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);

	body->setUserPointer(this); //connect the btrigidbody to this phyrigidbody for raytracing etc.

	//add to world
	aPhysicsWorld.getDynamicsWorld()._Get()->addRigidBody(body);

	//push data to world and object
	m_CollisionShape = std::shared_ptr<btCollisionShape>(colShape);
	m_RigidBody = std::shared_ptr<btRigidBody>(body);

}

void RigidBody::prePhysicsStepSync(void)
{
	//Check if ECS transform position has changed
	Math::Vector3 ecsPos = m_ECSPhysicsBody._Get()->getPosition();
	btVector3     btPos = m_Transform._Get()->getOrigin();

	if
		(
			ecsPos.x != btPos.getX() ||
			ecsPos.y != btPos.getY() ||
			ecsPos.z != btPos.getZ()
			)
	{
		m_Transform._Get()->setOrigin(btVector3(ecsPos.x, ecsPos.y, ecsPos.z));
		m_RigidBody._Get()->activate(true);
	}

	//Check if ECS transform rotation has changed
	Math::Quaternion ecsRot = m_ECSPhysicsBody._Get()->getRotation();
	btQuaternion     btRot = m_Transform._Get()->getRotation();

	if
		(
			ecsRot.x != btRot.getX() ||
			ecsRot.y != btRot.getY() ||
			ecsRot.z != btRot.getZ() ||
			ecsRot.w != btRot.getW()
			)
	{
		m_Transform._Get()->setRotation(btQuaternion(ecsRot.z, ecsRot.y, ecsRot.x, ecsRot.w));
		m_RigidBody._Get()->activate(true);

	}

	//update m_Transform data with ECS data
	m_RigidBody._Get()->setCenterOfMassTransform(*m_Transform._Get());

}
void RigidBody::postPhysicsStepSync(void)
{
	//retrieve sim object transform data
	*m_Transform._Get() = m_RigidBody._Get()->getCenterOfMassTransform();

}

//Math::Vector3 RigidBody::getPosition(void)
//{
//	return Math::Vector3(m_Transform._Get()->getOrigin());
//
//}
//
//Math::Quaternion RigidBody::getRotation(void)
//{
//	return Math::Quaternion(m_Transform._Get()->getRotation());
//
//}

//std::weak_ptr<ECS::Rigidbody> RigidBody::getECSRigidbody(void)
//{
//	return m_ECSRigidbody;
//
//}