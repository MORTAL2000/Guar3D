#ifndef GUAR_ECS_CAMERA_H
#define GUAR_ECS_CAMERA_H

//ecsinc
#include "../Observer/Observer.h"
//gfxinc
#include <Graphics\ClearMode\ClearMode.h>
#include <Graphics\GraphicsTypes.h>

//math inc
#include <Math\Vector3\Vector3.h>
#include <Math\Vector2\Vector2.h>
//stdinc
#include <memory>

namespace guar
{
	namespace GFX { class RenderObserver; }
	namespace GFX { class RenderCamera; }

	namespace ECS
	{
		class Transform;
		class GameObject;

		class Camera : public Observer
		{
			friend class SceneGraph;
			friend class Renderer;
			friend ECS::GameObject;

			std::weak_ptr<Transform>         m_Transform;
			std::weak_ptr<GFX::RenderCamera> m_RenderCamera;

			void update(void) override;
			void draw(void) override;

		public:
			//Vector3     getPosition                 (void);
			//Vector3     getRotation                 (void);
			//float       getNearClippingDistance     (void);
			//float       getFarClippingDistance      (void);
			//float       getFieldOfView              (void);
			GFX::Color    getClearColor               (void);
			Math::Vector3 getWorldPointFromScreenPoint(const Math::Vector2 &aScreenPoint, const float &aWorldSpaceDistance); 
			Math::Vector3 getWorldPointFromScreenPoint(const Math::Vector2 &aScreenPoint);
			
			void setPosition             (const Math::Vector3 &aPosition            );
			void setRotation             (const Math::Vector3 &aRotation            );
			void setNearClippingDistance (const float         &aNearClippingDistance);
			void setFarClippingDistance  (const float         &aFarClippingDistance );
			void setFieldOfView          (const float         &aFieldOfView         );
			void setClearColor           (const GFX::Color    &aClearColor          );
			void setViewportPosition     (const Math::Vector2 &aViewportPosition    ); 
			void setViewportSize         (const Math::Vector2 &aViewportSize        ); 

			void setClearMode(const bool &aEnabled, const GFX::ClearMode::ClearModeCode &aClearMode);// { m_RenderCamera._Get()->setClearMode(aEnabled, aClearMode); }

			GFX::RenderObserver* getRenderObserver(void) override;

		};

	}

}

#endif