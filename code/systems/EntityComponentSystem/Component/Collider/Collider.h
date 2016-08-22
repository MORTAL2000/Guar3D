#ifndef GUAR_ECS_COLLIDER_H
#define GUAR_ECS_COLLIDER_H

//ecs inc
#include "../Component.h"
//math inc
#include <Math\Vector3\Vector3.h>
//std inc
#include <memory>

namespace guar
{
	namespace PHY { class Collider; }

	namespace ECS
	{
		class Collider : public Component
		{
		protected:
			std::shared_ptr<PHY::Collider> m_Collider;

		public:
			std::weak_ptr<PHY::Collider> getCollider(void);
			
		};


	}


}

#endif