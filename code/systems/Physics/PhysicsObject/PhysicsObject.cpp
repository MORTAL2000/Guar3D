#include "PhysicsObject.h"
//physics inc
#include "../PhysicsWorld/PhysicsWorld.h"
//ecs inc
#include <EntityComponentSystem\Component\PhysicsBody\Rigidbody\Rigidbody.h>
//External inc
#include <Bullet\btBulletDynamicsCommon.h>

using namespace guar;
using namespace PHY;

PhysicsObject::PhysicsObject(PhysicsWorld &aPhysicsWorld, std::weak_ptr<ECS::PhysicsBody> aECSPhysicsBody) :
	m_ECSPhysicsBody(aECSPhysicsBody),
	m_Transform(new btTransform())
{}

Math::Vector3 PhysicsObject::getPosition(void)
{	
	return Math::Vector3(m_Transform._Get()->getOrigin());

}

Math::Quaternion PhysicsObject::getRotation(void)
{
	return Math::Quaternion(m_Transform._Get()->getRotation());

}

void PhysicsObject::setPosition(const Math::Vector3    &aPosition)
{
	m_Transform._Get()->setOrigin(btVector3(aPosition.x, aPosition.y, aPosition.z));

}

void PhysicsObject::setRotation(const Math::Quaternion &aRotation)
{
	m_Transform._Get()->setRotation(btQuaternion(aRotation.x, aRotation.y, aRotation.z, aRotation.w));
	
}

std::weak_ptr<ECS::PhysicsBody> PhysicsObject::getECSPhysicsBody(void)
{
	return m_ECSPhysicsBody;

}