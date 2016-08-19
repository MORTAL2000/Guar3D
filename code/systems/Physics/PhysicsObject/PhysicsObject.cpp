#include "PhysicsObject.h"
//physics inc
#include "../PhysicsWorld/PhysicsWorld.h"
//ecs inc
#include <EntityComponentSystem\Component\Rigidbody\Rigidbody.h>
//External inc
#include <Bullet\btBulletDynamicsCommon.h>

using namespace guar;
using namespace PHY;

PhysicsObject::PhysicsObject(PhysicsWorld &aPhysicsWorld, std::weak_ptr<ECS::Rigidbody> aECSRigidbody) :
	m_ECSRigidbody(aECSRigidbody),
	m_Transform(new btTransform())
{
	//create a dynamic rigidbody
	float size = 2.5f;
	btCollisionShape* colShape = new btBoxShape(btVector3(size, size, size));//new btSphereShape(btScalar(1.f));
	
	/// Create Dynamic Objects
	m_Transform._Get()->setIdentity();

	btScalar	mass(1.f);

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
	
	//add to world
	aPhysicsWorld.getDynamicsWorld()._Get()->addRigidBody(body);
	
	//push data to world and object
	m_CollisionShape = std::shared_ptr<btCollisionShape>(colShape);
	m_RigidBody      = std::shared_ptr<btRigidBody>     (body);

}

void PhysicsObject::prePhysicsStepSync(void)
{
	//Check if ECS transform position has changed
	Math::Vector3 ecsPos = m_ECSRigidbody._Get()->getPosition();
	btVector3     btPos  = m_Transform._Get()->getOrigin();
	
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

	////Check if ECS transform rotation has changed
	//Math::Vector3 ecsRot = m_ECSRigidbody._Get()->getRotation();
	//btScalar x, y, z; m_Transform._Get()->getBasis().getEulerZYX(z,y,x);
	//
	//if
	//(
	//	ecsRot.x != x ||
	//	ecsRot.y != y ||
	//	ecsRot.z != z
	//)
	//{
	//	m_Transform._Get()->setRotation(btQuaternion(ecsRot.z, ecsRot.y, ecsRot.x));
	//	m_RigidBody._Get()->activate(true);
	//}


	//update m_Transform data with ECS data
	m_RigidBody._Get()->setCenterOfMassTransform(*m_Transform._Get());

}
void PhysicsObject::postPhysicsStepSync(void)
{
	//retrieve sim object transform data
	*m_Transform._Get() = m_RigidBody._Get()->getCenterOfMassTransform();
		
}

Math::Vector3 PhysicsObject::getPosition(void)
{	
	return Math::Vector3
	(
		m_Transform._Get()->getOrigin().getX(),
		m_Transform._Get()->getOrigin().getY(),
		m_Transform._Get()->getOrigin().getZ()

	);

}

Math::Quaternion PhysicsObject::getRotation(void)
{
	btQuaternion btQuat = m_Transform._Get()->getRotation();
	Math::Quaternion quat;

	quat.x = btQuat.getX();
	quat.y = btQuat.getY();
	quat.z = btQuat.getZ();
	quat.w = btQuat.getW();

	return quat;

}