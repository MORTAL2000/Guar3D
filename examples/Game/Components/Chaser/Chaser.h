#ifndef GAME_COMPONENTS_CHASER_H
#define GAME_COMPONENTS_CHASER_H

//ecs inc
#include <EntityComponentSystem\Component\Component.h>
//std inc
#include <memory>

namespace guar { namespace ECS { class Transform; } }
namespace guar { namespace ECS { class Camera;    } }

namespace Game
{
	class Chaser : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;

		std::weak_ptr<guar::ECS::Transform> m_PlayerTransform;
		std::weak_ptr<guar::ECS::Camera>    m_PlayerCamera;

		void init(void) override;
		void update(void) override;

	};

}

#endif