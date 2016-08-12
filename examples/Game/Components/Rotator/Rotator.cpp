#include "Rotator.h"

#include<Time\Time.h>
#include<Input\Input.h>
#include<Math\Vector3\Vector3.h>
#include<EntityComponentSystem\GameObject\GameObject.h>
#include<EntityComponentSystem\Component\Transform\Transform.h>

using namespace Game;
using namespace guar;

void Rotator::update(void)
{
	m_Transform = getGameObject()->findComponent<guar::ECS::Transform>();

	static float i = 0;

	i += 0.025f;
	float radius = 70.0f;

	{
		Math::Vector3 delta = Math::Vector3();

		if (Input::getKeyDown(Key::I))
			delta += Math::Vector3::Forward;
		if (Input::getKeyDown(Key::K))
			delta += Math::Vector3::Backward;
		if (Input::getKeyDown(Key::J))
			delta += Math::Vector3::Left;
		if (Input::getKeyDown(Key::L))
			delta += Math::Vector3::Right;
	
		delta *= Time::getDeltaTime() * 30.0f;

		m_Transform._Get()->translate(delta);
	
	}
	
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

		m_Transform._Get()->rotate(delta);

	}

}