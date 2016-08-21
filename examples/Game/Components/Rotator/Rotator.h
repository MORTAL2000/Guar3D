#ifndef GAME_COMPONENT_ROTATOR_H
#define GAME_COMPONENT_ROTATOR_H

//ecs inc
#include<EntityComponentSystem\Component\Component.h>
//math inc
#include<Math\Vector3\Vector3.h>

namespace guar { namespace ECS { class Transform; } }

namespace Game
{
	class Rotator : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;
		guar::Math::Vector3 m_Rotation;

		void init  (void) override;
		void update(void) override;

	};

}

#endif