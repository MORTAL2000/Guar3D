#ifndef GAME_COMPONENT_PLAYERCONTROLLER_H
#define GAME_COMPONENT_PLAYERCONTROLLER_H

#include <EntityComponentSystem\Component\Component.h>

namespace guar { namespace ECS { class Transform; } }

namespace Game
{
	class PlayerController : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;

		void start(void) override
		{


		}

		void update(void) override;

	};

}

#endif