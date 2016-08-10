#ifndef GAME_COMPONENT_SPINNER_H
#define GAME_COMPONENT_SPINNER_H
/*
 * Spinner.h
 *
 *
*/

#include<EntityComponentSystem\Component\Component.h>

namespace guar { namespace ECS { class Transform; } }

namespace Game
{
	class Spinner : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;

		void update(void) override;

	};

}

#endif