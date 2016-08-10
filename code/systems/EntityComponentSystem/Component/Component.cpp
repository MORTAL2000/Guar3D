#include "Component.h"
//ecsinc
#include "../GameObject/GameObject.h"
//debuginc
#include <debug\Debug.h>

using namespace guar;
using namespace ECS;

Component::Component() :
	m_GameObject(0)
{}

Component::~Component()
{
	Debug::log(getGameObject()->getName(), "'s component is destructing");

}