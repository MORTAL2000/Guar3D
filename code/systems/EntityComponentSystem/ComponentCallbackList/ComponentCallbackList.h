#ifndef GUAR_ENTITYCOMPONENTSYSTEM_COMPONENTCALLBACKLIST_H
#define GUAR_ENTITYCOMPONENTSYSTEM_COMPONENTCALLBACKLIST_H

#include <list>
#include <functional>
#include <tuple>

namespace guar
{
	namespace ECS
	{
		class Component;

		class ComponentCallbackList
		{
			std::list<std::tuple<Component*,std::function<void(void)>>> m_CallbackList;

		public:
			void update(void);
			void push_back(const std::tuple<Component*, std::function<void(void)>> &aItem);

		};

	}

}

#endif