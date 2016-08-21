#include "PlayerController.h"

//ECS inc
#include <EntityComponentSystem\Component\Transform\Transform.h>
#include <EntityComponentSystem\GameObject\GameObject.h>
//Input inc
#include <Input\Input.h>
//Math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Constants.h>
//Time inc
#include <Time\Time.h>
//std inc
#include <math.h>

using namespace Game;
using namespace guar;

void PlayerController::init(void)
{
	m_Transform = getGameObject()->findComponent<guar::ECS::Transform>();

}

void PlayerController::update(void)
{
	//Rotate
	{
		Math::Vector3 delta = Math::Vector3();

		if (Input::getKeyDown(Key::E))
			delta += Math::Vector3::Up;

		if (Input::getKeyDown(Key::Q))
			delta += Math::Vector3::Down;

		if (Input::getKeyDown(Key::R))
			delta += Math::Vector3::Left;

		if (Input::getKeyDown(Key::F))
			delta += Math::Vector3::Right;
		
		delta *= Time::getDeltaTime() * 5.0f;

		m_Rotation += delta;
		
		m_Transform._Get()->setRotation(m_Rotation);

	}

	//Translate
	{
		Math::Vector3 delta = Math::Vector3();

		if (Input::getKeyDown(Key::W))
		{
			delta.x += sin(m_Rotation.y);
			delta.z -= cos(m_Rotation.y);

		}

		if (Input::getKeyDown(Key::S))
		{
			delta.x -= sin(m_Rotation.y);
			delta.z += cos(m_Rotation.y);

		}

		if (Input::getKeyDown(Key::A))
		{
			delta.x -= sin(m_Rotation.y + (90.0f * Math::PI / 180));
			delta.z += cos(m_Rotation.y + (90.0f * Math::PI / 180));

		}

		if (Input::getKeyDown(Key::D))
		{
			delta.x += sin(m_Rotation.y + (90.0f * Math::PI / 180));
			delta.z -= cos(m_Rotation.y + (90.0f * Math::PI / 180));

		}

		if (Input::getKeyDown(Key::LEFT_CONTROL) || Input::getKeyDown(Key::C))
			delta.y -= 1;

		if (Input::getKeyDown(Key::SPACE))
			delta.y += 1;

		delta *= Time::getDeltaTime() * 60.0f;

		m_Transform._Get()->translate(delta);

	}

}