#ifndef GAME_COMPONENT_PLAYERCONTROLLER_H
#define GAME_COMPONENT_PLAYERCONTROLLER_H

//ecs inc
#include <EntityComponentSystem\Component\Component.h>
//math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Vector2\Vector2.h>
//std inc
#include <memory>

namespace guar { namespace ECS { class Transform; } }
namespace guar { namespace ECS { class Camera   ; } }

namespace Game
{
	class PlayerController : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;
		std::weak_ptr<guar::ECS::Camera> m_Camera;

		guar::Math::Vector3 m_Rotation;
		float m_Distance;

		float m_ReloadTimer;

		void init  (void) override;
		//void start (void) override;
		void update(void) override;

	};

}

#endif