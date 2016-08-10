#ifndef GUAR_ECS_COMPONENTCOLLECTION_H
#define GUAR_ECS_COMPONENTCOLLECTION_H
/*
 * ComponentCollection.h
 * 
*/

//stdlibinc
#include<vector>

namespace guar
{
	namespace ECS
	{
		class Component;

		class ComponentCollection
		{
		private:
			std::vector<Component*> m_ComponentVector;

		public:
			void push_back(Component* aComponent) { m_ComponentVector.push_back(aComponent); }
			const int size(void) { return m_ComponentVector.size(); }
			Component* operator[](int aIndex);

		};

	}

}

#endif