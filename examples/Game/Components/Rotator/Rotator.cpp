#include "Rotator.h"

//ecs inc
#include<EntityComponentSystem\GameObject\GameObject.h>
#include<EntityComponentSystem\Component\Transform\Transform.h>
//math inc
#include<Math\Vector3\Vector3.h>
#include <Math\Constants.h>
//time inc
#include<Time\Time.h>
//input inc
#include<Input\Input.h>

using namespace Game;
using namespace guar;
#include <Debug\Debug.h>
void Rotator::init(void)
{
	m_Transform = getGameObject()->findComponent<guar::ECS::Transform>();

	m_Rotation = m_Transform._Get()->getEulerAngles();

	Debug::log(m_Rotation);
	
}

void Rotator::update(void)
{
	//Rotate
	{
		Math::Vector3 delta = Math::Vector3();

		if (Input::getKeyDown(Key::U))
			delta += Math::Vector3::Up;

		if (Input::getKeyDown(Key::O))
			delta += Math::Vector3::Down;

		if (Input::getKeyDown(Key::Y))
			delta += Math::Vector3::Left;

		if (Input::getKeyDown(Key::H))
			delta += Math::Vector3::Right;

		delta *= Time::getDeltaTime() * 5.0f;

		m_Rotation += delta;

		m_Transform._Get()->setRotation(m_Rotation);

	}

	//Translate
	{
		Math::Vector3 delta = Math::Vector3();

		if (Input::getKeyDown(Key::I))
		{
			delta.x += sin(m_Rotation.y);
			delta.z -= cos(m_Rotation.y);

		}

		if (Input::getKeyDown(Key::K))
		{
			delta.x -= sin(m_Rotation.y);
			delta.z += cos(m_Rotation.y);

		}

		if (Input::getKeyDown(Key::J))
		{
			delta.x -= sin(m_Rotation.y + (90.0f * Math::PI / 180));
			delta.z += cos(m_Rotation.y + (90.0f * Math::PI / 180));

		}

		if (Input::getKeyDown(Key::L))
		{
			delta.x += sin(m_Rotation.y + (90.0f * Math::PI / 180));
			delta.z -= cos(m_Rotation.y + (90.0f * Math::PI / 180));

		}

		delta *= Time::getDeltaTime() * 60.0f;

		m_Transform._Get()->translate(delta);

	}
	

}