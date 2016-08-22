#include "PhysicsBody.h"
//ecs inc
#include "../Transform/Transform.h"
#include "../../GameObject/GameObject.h"
#include "../../SceneGraph/SceneGraph.h"
//phy inc
#include <Physics\PhysicsObject\PhysicsObject.h>
#include <Physics\PhysicsObject\RigidBody\RigidBody.h>
#include <Physics\SceneGraph\SceneGraph.h>
//debug inc
#include <Debug\Debug.h>

using namespace guar;
using namespace ECS;

void PhysicsBody::init(const std::weak_ptr<PHY::PhysicsObject> &aPhysicsObject)
{
	//Rigidbody requires a transform
	m_Transform = getGameObject()->findComponent<Transform>();
	m_PhysicsObject = aPhysicsObject;

	m_PhysicsObject._Get()->setPosition(m_Transform._Get()->getPosition());
	m_PhysicsObject._Get()->setRotation(m_Transform._Get()->getRotation());

}

void PhysicsBody::update(void)
{
	m_Transform._Get()->setPosition(m_PhysicsObject._Get()->getPosition());
	m_Transform._Get()->setRotation(m_PhysicsObject._Get()->getRotation());

}

Math::Vector3    PhysicsBody::getPosition(void) { return m_Transform._Get()->getPosition(); }
Math::Quaternion PhysicsBody::getRotation(void) { return m_Transform._Get()->getRotation(); }

void PhysicsBody::setPosition(const Math::Vector3 &aPosition) { m_Transform._Get()->setPosition(aPosition); }