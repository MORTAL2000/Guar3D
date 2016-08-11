#include "Orbiter.h"

//ECS inc
#include <EntityComponentSystem\Component\Transform\Transform.h>
#include <EntityComponentSystem\GameObject\GameObject.h>
//Math
#include <Math\Vector3\Vector3.h>
//std inc
#include <math.h>

using namespace Game;

void Orbiter::update()
{
	m_Transform = getGameObject()->findComponent<guar::ECS::Transform>();

	m_Transform._Get()->setPosition(guar::Math::Vector3(0, -5.0f, 10.0f));


}