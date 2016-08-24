#include "Camera.h"

#include "../../GameObject/GameObject.h"
#include "../Transform/Transform.h"
#include "../../../Graphics/GraphicsTypes.h"

#include "../../../Graphics/RenderCamera/RenderCamera.h"

using namespace guar;
using namespace ECS;
using namespace GFX;

void Camera::update(void)
{
	if (m_Transform._Get() == 0)
		m_Transform = getGameObject()->findComponent<Transform>();
	
	if (m_Transform._Get() == 0)
		return;

	m_RenderCamera._Get()->setPosition(m_Transform._Get()->getPosition());
	m_RenderCamera._Get()->setRotation(m_Transform._Get()->getRotation());

}

void Camera::draw(void)
{
	m_RenderCamera._Get()->draw();

}

Math::Vector3 Camera::getWorldPointFromScreenPoint(const Math::Vector2 &aScreenPoint, const float &aWorldSpaceDistance)
{
	return m_RenderCamera._Get()->getWorldPointFromScreenPoint(aScreenPoint, aWorldSpaceDistance);

}

Math::Vector3 Camera::getWorldPointFromScreenPoint(const Math::Vector2 &aScreenPoint)
{
	return m_RenderCamera._Get()->getWorldPointFromScreenPoint(aScreenPoint);

}

//Vector3 Camera::getPosition				(void) { return m_RenderCamera.getPosition();             }
//Vector3 Camera::getRotation				(void) { return m_RenderCamera.getRotation();             }
//float   Camera::getNearClippingDistance (void) { return m_RenderCamera.getNearClippingDistance(); }
//float   Camera::getFarClippingDistance  (void) { return m_RenderCamera.getFarClippingDistance();  }
//float   Camera::getFieldOfView          (void) { return m_RenderCamera.getFieldOfView();          }
Color   Camera::getClearColor           (void) { return m_RenderCamera._Get()->getClearColor();           }

void Camera::setPosition             (const Math::Vector3 &aPosition            ) { m_RenderCamera._Get()->setPosition(aPosition);						 }
void Camera::setRotation             (const Math::Vector3 &aRotation            ) { m_RenderCamera._Get()->setRotation(aRotation);						 }
void Camera::setNearClippingDistance (const float         &aNearClippingDistance) { m_RenderCamera._Get()->setNearClippingDistance(aNearClippingDistance); }
void Camera::setFarClippingDistance  (const float         &aFarClippingDistance ) { m_RenderCamera._Get()->setFarClippingDistance(aFarClippingDistance);   }
void Camera::setFieldOfView          (const float         &aFieldOfView         ) { m_RenderCamera._Get()->setFieldOfView(aFieldOfView);                   }
void Camera::setClearColor           (const Color         &aClearColor          ) { m_RenderCamera._Get()->setClearColor(aClearColor);                     }
void Camera::setViewportPosition     (const Math::Vector2 &aViewportPosition    ) { m_RenderCamera._Get()->setViewportPosition(aViewportPosition); }
void Camera::setViewportSize         (const Math::Vector2 &aViewportSize        ) { m_RenderCamera._Get()->setViewportSize    (aViewportSize    ); }


void Camera::setClearMode(const bool &aEnabled, const GFX::ClearMode::ClearModeCode &aClearMode) { m_RenderCamera._Get()->setClearMode(aEnabled, aClearMode); }

GFX::RenderObserver* Camera::getRenderObserver(void) { return m_RenderCamera._Get(); }