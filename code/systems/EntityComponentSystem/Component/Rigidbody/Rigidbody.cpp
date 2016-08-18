#include "Rigidbody.h"

//ecs inc
#include "../Transform/Transform.h"
#include "../../GameObject/GameObject.h"
#include "../../SceneGraph/SceneGraph.h"
//phy inc
#include <Physics\PhysicsObject\PhysicsObject.h>
#include <Physics\SceneGraph\SceneGraph.h>
//debug inc
#include <Debug\Debug.h>

using namespace guar;
using namespace ECS;

void Rigidbody::init(void)
{
	//Rigidbody requires a transform
	m_Transform = getGameObject()->findComponent<Transform>();

	//Connect to corresponding PHY::Rigidbody in the phy scenegraph
	m_PhysicsObject = getGameObject()->getSceneGraph()._Get()->getPhysicsScene()._Get()->createRigidBody(getGameObject()->findComponent<Rigidbody>());

}

void Rigidbody::update(void)
{
	m_Transform._Get()->setPosition(m_PhysicsObject._Get()->getPosition());
	m_Transform._Get()->setRotation(m_PhysicsObject._Get()->getRotation());

	//static int test = 0;
	//
	//if (test++ == 100000)
	//{
	//	m_Transform._Get()->setPosition(Math::Vector3(10, 50, 0));
	//
	//}
	//
	//if (test == 300000)
	//{
	//	m_Transform._Get()->setPosition(Math::Vector3(-10, 60, 0));
	//
	//}
	//
	//if (test == 600000)
	//{
	//	m_Transform._Get()->setPosition(Math::Vector3(-50, 60, 0));
	//
	//}
	
}

Math::Vector3 Rigidbody::getPosition(void) { return m_Transform._Get()->getPosition(); }
Math::Vector3 Rigidbody::getRotation(void) { return m_Transform._Get()->getRotation(); }

void Rigidbody::setPosition(const Math::Vector3 &aPosition) { m_Transform._Get()->setPosition(aPosition); }