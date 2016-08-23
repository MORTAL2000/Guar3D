#ifndef GAME_COMPONENTS_CHASER_H
#define GAME_COMPONENTS_CHASER_H

//ecs inc
#include <EntityComponentSystem\Component\Component.h>
//std inc
#include <memory>

namespace guar { namespace ECS { class Transform; } }

namespace Game
{
	class Chaser : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;
		std::weak_ptr<guar::ECS::Transform> m_PlayerTransform;

		void init(void) override;
		void update(void) override;

	};

}

#endif