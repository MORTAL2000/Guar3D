#ifndef GAME_COMPONENT_SKYPLAYERCONTROLLER_H
#define GAME_COMPONENT_SKYPLAYERCONTROLLER_H

#include <EntityComponentSystem\Component\Component.h>
#include <Engine\Engine.h>
#include <EntityComponentSystem\SceneGraph\SceneGraph.h>
#include <EntityComponentSystem\GameObject\GameObject.h>

namespace guar { namespace ECS { class Transform; } }

namespace Game
{
	class SkyPlayer : public guar::ECS::Component
	{
		std::weak_ptr<guar::ECS::Transform> m_Transform;		
		std::weak_ptr<guar::ECS::Transform> m_MainScenePlayerTransform;

		void update(void) override
		{
			m_MainScenePlayerTransform = guar::Engine::findScene("mainScene")._Get()->getRootObject("The Player")._Get()->findComponent<guar::ECS::Transform>();
			m_Transform = getGameObject()->findComponent<guar::ECS::Transform>();

			m_Transform._Get()->setRotation
			(
				m_MainScenePlayerTransform._Get()->getRotation()

			);

		}

	};

}

#endif