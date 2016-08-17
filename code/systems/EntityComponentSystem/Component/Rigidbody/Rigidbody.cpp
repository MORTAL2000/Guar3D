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
	m_PhysicsObject = getGameObject()->getSceneGraph()._Get()->getPhysicsScene()._Get()->createRigidBody();

}

void Rigidbody::update(void)
{
	if (m_Transform._Get() == 0)
		m_Transform = getGameObject()->findComponent<Transform>();

	if (m_Transform._Get() == 0)
		return;

	if (m_PhysicsObject._Get() != 0)
	{
		m_Transform._Get()->setPosition(m_PhysicsObject._Get()->getPosition());

	}

	Debug::log(m_Transform._Get()->getPosition(),"\n");

}