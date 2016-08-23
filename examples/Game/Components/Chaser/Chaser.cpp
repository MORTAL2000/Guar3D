#include "Chaser.h"
//ecs inc
#include <EntityComponentSystem\GameObject\GameObject.h>
#include <EntityComponentSystem\Component\Transform\Transform.h>
#include <EntityComponentSystem\SceneGraph\SceneGraph.h>
//math inc
#include <Math\Constants.h>

using namespace Game;

void Chaser::init(void)
{
	m_Transform       = getGameObject()->findComponent<guar::ECS::Transform>();
	m_PlayerTransform = getGameObject()->getSceneGraph()._Get()->findGameObject("The Player")._Get()->findComponent<guar::ECS::Transform>();

}

void Chaser::update(void)
{
	guar::Math::Vector3 position = guar::Math::Vector3();

	position  = m_PlayerTransform._Get()->getPosition();
	position += m_PlayerTransform._Get()->getForwardVector();

	m_Transform._Get()->setPosition
	(
		//m_PlayerTransform._Get()->getPosition() + m_PlayerTransform._Get()->getForwardVector()
		position

	);

}