#include "ComponentCallbackList.h"

#include <Debug\Debug.h>
#include "../GameObject/GameObject.h"

using namespace guar;
using namespace ECS;

void ComponentCallbackList::update(void)
{
	while (m_CallbackList.size() > 0)
	{
		//Debug::log("ComponentCallbackList::update\n");

		std::get<0>(m_CallbackList.front())->m_Ready = true;
		std::get<1>(m_CallbackList.front())();
		m_CallbackList.pop_front();

	}

}

void ComponentCallbackList::push_back(const std::tuple<Component*, std::function<void(void)>> &aItem)
{
	m_CallbackList.push_back(aItem);

}