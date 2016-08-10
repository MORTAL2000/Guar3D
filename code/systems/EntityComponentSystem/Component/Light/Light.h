#ifndef GUAR_ECS_LIGHT_H
#define GUAR_ECS_LIGHT_H
/*
 * 
 * 
*/
//ecsinc
#include "../Observer/Observer.h"
//gfxinc
#include "../../../Graphics/RenderLight/RenderLight.h"
//mathinc
#include <Math/Vector3/Vector3.h>

namespace guar
{
	namespace GFX { class RenderObserver; }

	namespace ECS
	{
		class Transform;

		class Light : public Observer
		{
			friend class Renderer;
			friend class SceneGraph;

			std::weak_ptr<Transform> m_Transform;
			GFX::RenderLight	     m_RenderLight;

			void update(void) override;
			void draw(void) override;

		public:
			Math::Vector3 getPosition			  (void) ;
			Math::Vector3 getRotation			  (void) ;
			float		  getNearClippingDistance (void) ;
			float		  getFarClippingDistance  (void) ;
			float		  getFieldOfView		  (void) ;

			void setPosition             (const Math::Vector3 &aPosition            ) ;
			void setRotation             (const Math::Vector3 &aRotation            ) ;
			void setNearClippingDistance (const float         &aNearClippingDistance) ;
			void setFarClippingDistance  (const float         &aFarClippingDistance ) ;
			void setFieldOfView          (const float         &aFieldOfView         ) ;

			GFX::RenderObserver* getRenderObserver(void) override { return &m_RenderLight; }

		};

	}

}

#endif