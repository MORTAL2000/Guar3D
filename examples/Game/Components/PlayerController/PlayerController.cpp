#include "PlayerController.h"

//ECS inc
#include <EntityComponentSystem\Component\Transform\Transform.h>
#include <EntityComponentSystem\GameObject\GameObject.h>
//Input inc
#include <Input\Input.h>
//Math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Constants.h>
//std inc
#include <math.h>

using namespace Game;
using namespace guar;

void PlayerController::update(void)
{
	m_Transform = getGameObject()->findComponent<guar::ECS::Transform>();
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

		delta *= 0.05f;

		m_Transform._Get()->rotate(delta);

	}

	{
		Math::Vector3 delta = Math::Vector3();

		if (Input::getKeyDown(Key::W))
		{
			delta.x += sin(m_Transform._Get()->getRotation().y);
			delta.z -= cos(m_Transform._Get()->getRotation().y);

		}

		if (Input::getKeyDown(Key::S))
		{
			delta.x -= sin(m_Transform._Get()->getRotation().y);
			delta.z += cos(m_Transform._Get()->getRotation().y);

		}

		if (Input::getKeyDown(Key::A))
		{
			delta.x -= sin(m_Transform._Get()->getRotation().y + (90.0f * Math::PI / 180));
			delta.z += cos(m_Transform._Get()->getRotation().y + (90.0f * Math::PI / 180));

		}

		if (Input::getKeyDown(Key::D))
		{
			delta.x += sin(m_Transform._Get()->getRotation().y + (90.0f * Math::PI / 180));
			delta.z -= cos(m_Transform._Get()->getRotation().y + (90.0f * Math::PI / 180));

		}

		if (Input::getKeyDown(Key::LEFT_CONTROL) || Input::getKeyDown(Key::C))
			delta.y -= 1;

		if (Input::getKeyDown(Key::SPACE))
			delta.y += 1;

		//delta.normalize();

		m_Transform._Get()->translate(delta); //std::cout << Graphics::getRenderTexture("")->getName() << "\n";

	}

}