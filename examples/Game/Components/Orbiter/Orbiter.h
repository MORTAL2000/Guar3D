#ifndef GAME_COMPONENTS_ORBITER_H
#define GAME_COMPONENTS_ORBITER_H

#include <EntityComponentSystem\Component\Component.h>

namespace guar { namespace ECS { class Transform; } }

namespace Game
{
	class Orbiter : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;

		void update(void) override;


	};

}

#endif