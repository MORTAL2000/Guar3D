#include "ComponentCollection.h"

using namespace guar;
using namespace ECS;

Component* ComponentCollection::operator[](int aIndex)
{
	if (aIndex >= m_ComponentVector.size())
		return 0;

	return m_ComponentVector[aIndex];

}