#ifndef GAME_COMPONENT_PLAYERCONTROLLER_H
#define GAME_COMPONENT_PLAYERCONTROLLER_H

//ecs inc
#include <EntityComponentSystem\Component\Component.h>
//math inc
#include <Math\Vector3\Vector3.h>
//std inc
#include <memory>

namespace guar { namespace ECS  { class  Transform; } }

namespace Game
{
	class PlayerController : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;

		guar::Math::Vector3 m_Rotation;

		void init  (void) override;
		//void start (void) override;
		void update(void) override;

	};

}

#endif