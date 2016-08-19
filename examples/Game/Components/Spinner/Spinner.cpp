#include "Spinner.h"

//ECS inc
#include <EntityComponentSystem\GameObject\GameObject.h>
#include <EntityComponentSystem\Component\Transform\Transform.h>
//Time inc
#include <Time\Time.h>

using namespace Game;
using namespace guar;

void Spinner::update(void)
{
	m_Transform = getGameObject()->findComponent<guar::ECS::Transform>();

	m_Transform._Get()->rotate(Math::Vector3::Right * Time::getDeltaTime());
	m_Transform._Get()->rotate(Math::Vector3::Up    * Time::getDeltaTime()*2.f);

}