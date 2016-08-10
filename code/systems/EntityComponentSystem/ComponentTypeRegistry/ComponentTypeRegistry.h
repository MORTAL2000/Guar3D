#ifndef GUAR_ECS_COMPONENTTYPEREGISTRY_H
#define GUAR_ECS_COMPONENTTYPEREGISTRY_H
/*
 * ComponentTypeRegistry
 * 
*/
//projinc
#include "../Component/Component.h"

//stdinc
#include <map>
#include <string>
#include <type_traits>
#include <iostream>

namespace guar
{
	namespace ECS
	{
		class ComponentTypeRegistry
		{
		private:
			static std::map<std::string, Component> m_ComponentMap;

		public:
			template <class T>
			static void registerNewComponentType(char* aNewTypeName)
			{
				static_assert(std::is_base_of<Component, T>::value == true, "T is not derived from Component and therefore cannot be registered.");

			}

		public:
			static void init();

		};

	}

}

#endif