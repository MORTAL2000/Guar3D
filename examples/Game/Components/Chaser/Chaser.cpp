#include "Chaser.h"
//ecs inc
#include <EntityComponentSystem\GameObject\GameObject.h>
#include <EntityComponentSystem\Component\Transform\Transform.h>
#include <EntityComponentSystem\SceneGraph\SceneGraph.h>
#include <EntityComponentSystem\Component\Camera\Camera.h>
//math inc
#include <Math\Constants.h>
//input inc
#include <Input\Input.h>
//debug inc
#include <Debug\Debug.h>
//time inc
#include <Time\Time.h>

using namespace Game;

void Chaser::init(void)
{
	m_Transform       = getGameObject()->findComponent<guar::ECS::Transform>();
	m_PlayerTransform = getGameObject()->getSceneGraph()._Get()->findGameObject("The Player")._Get()->findComponent<guar::ECS::Transform>();
	m_PlayerCamera    = getGameObject()->getSceneGraph()._Get()->findGameObject("The Player")._Get()->findComponent<guar::ECS::Camera>();

}

void Chaser::update(void)
{
	guar::Math::Vector3 position = guar::Math::Vector3();
	
	////chase forward vec
	//position = m_PlayerTransform._Get()->getPosition();
	//position += m_PlayerTransform._Get()->getForwardVector()*5.f;

	
	//guar::Debug::log(position, "\n");

	m_Transform._Get()->setPosition
	(
		position

	);

	m_Transform._Get()->rotate(guar::Math::Vector3(1.f, 0.2f, 0.4f)*guar::Time::getDeltaTime());

}