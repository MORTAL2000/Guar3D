#include "Light.h"

#include "../Transform/Transform.h"
#include "../../GameObject/GameObject.h"
#include "../../../Graphics/Graphics.h"
#include "../../../Graphics/RenderLight/RenderLight.h"
#include "../../../Graphics/RenderObserver/RenderObserver.h"

using namespace guar;
using namespace ECS;


void Light::update(void)
{
	if (m_Transform._Get() == 0)
		m_Transform = getGameObject()->findComponent<Transform>();

	if (m_Transform._Get() == 0)
		return;

	m_RenderLight._Get()->setPosition(m_Transform._Get()->getPosition());
	m_RenderLight._Get()->setRotation(m_Transform._Get()->getRotation());

}

void Light::draw(void)
{
	m_RenderLight._Get()->draw();


}

Math::Vector3    Light::getPosition             (void) { return m_RenderLight._Get()->getPosition(); }
Math::Quaternion Light::getRotation             (void) { return m_RenderLight._Get()->getRotation(); }
float		     Light::getNearClippingDistance (void) { return m_RenderLight._Get()->getNearClippingDistance(); }
float		     Light::getFarClippingDistance  (void) { return m_RenderLight._Get()->getFarClippingDistance(); }
float		     Light::getFieldOfView          (void) { return m_RenderLight._Get()->getFieldOfView(); }



void Light::setPosition				(const Math::Vector3 &aPosition      ) { m_RenderLight._Get()->setPosition(aPosition); }
void Light::setRotation				(const Math::Vector3 &aRotation      ) { m_RenderLight._Get()->setRotation(aRotation); }
void Light::setNearClippingDistance (const float   &aNearClippingDistance) { m_RenderLight._Get()->setNearClippingDistance(aNearClippingDistance); }
void Light::setFarClippingDistance  (const float   &aFarClippingDistance ) { m_RenderLight._Get()->setFarClippingDistance(aFarClippingDistance); }
void Light::setFieldOfView          (const float   &aFieldOfView         ) { m_RenderLight._Get()->setFieldOfView(aFieldOfView); }
