#ifndef GUAR_ECS_BOX_H
#define GUAR_ECS_BOX_H

#include "../Collider.h"
#include <Math\Vector3\Vector3.h>

namespace guar
{
	namespace ECS
	{
		class BoxCollider : public Collider
		{
			Math::Vector3 m_Size;

			void init(void) override;

		public:
			void setSize(const Math::Vector3 &aSize);

		};

	}
	
}

#endif