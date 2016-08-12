#include "RenderObserver.h"

//gfx inc
#include "../OpenGL/OpenGL.h"
#include "../Graphics.h"
#include "../RenderTexture/RenderTexture.h"

using namespace guar;
using namespace GFX;

//*************
// Constructors
//*************
RenderObserver::RenderObserver() :
	m_Position(),
	m_Rotation(),
	m_NearClippingDistance(0.01f),
	m_FarClippingDistance(1000.0f),
	m_FieldOfView(90.0f),
	m_RenderTexture(),
	m_ViewportSize(100,100)

{}

//******************
// Getters & Setters
//******************
Math::Vector3 RenderObserver::getPosition             (void) { return m_Position;             }
Math::Vector3 RenderObserver::getRotation             (void) { return m_Rotation;             }
float         RenderObserver::getNearClippingDistance (void) { return m_NearClippingDistance; }
float         RenderObserver::getFarClippingDistance  (void) { return m_FarClippingDistance;  }
float         RenderObserver::getFieldOfView          (void) { return m_FieldOfView;          }

void RenderObserver::setPosition             (const Math::Vector3  &aPosition            ) { m_Position             = aPosition;             }
void RenderObserver::setRotation             (const Math::Vector3  &aRotation            ) { m_Rotation             = aRotation;             }
void RenderObserver::setNearClippingDistance (const float    &aNearClippingDistance) { m_NearClippingDistance = aNearClippingDistance; }
void RenderObserver::setFarClippingDistance  (const float    &aFarClippingDistance ) { m_FarClippingDistance  = aFarClippingDistance;  }
void RenderObserver::setFieldOfView          (const float    &aFieldOfView         ) { m_FieldOfView          = aFieldOfView;          }

//********************************
// Member function implementations
//********************************

void RenderObserver::draw(void)
{
	if (m_RenderTexture._Get() != 0)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_RenderTexture._Get()->getFBOHandle());
		glViewport(0, 0, m_RenderTexture._Get()->getTextureSize().x, m_RenderTexture._Get()->getTextureSize().y);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}
	else
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
			
}