#ifndef GAME_COMPONENT_ROTATOR_H
#define GAME_COMPONENT_ROTATOR_H

#include<EntityComponentSystem\Component\Component.h>

namespace guar { namespace ECS { class Transform; } }

namespace Game
{
	class Rotator : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;

		void update(void) override;

	};

}

#endif