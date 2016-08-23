#include "RenderCamera.h"

#include "../RenderTexture/RenderTexture.h"
#include "../OpenGL/OpenGL.h"
#include "../Graphics.h"

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include <Math/Constants.h>

using namespace guar;
using namespace GFX;

RenderCamera::RenderCamera() : RenderObserver(), 
	m_ClearColor(0.535f, 0.535f, 0.8f, 1.0f),
	m_ViewportPosition(0, 0)
    
{}

void RenderCamera::draw(void)
{
	RenderObserver::draw(); 
	
	glViewport(0.01f*m_ViewportPosition.x*Graphics::getWindowSize().x, 0.01f*m_ViewportPosition.y*Graphics::getWindowSize().y, (0.01f*m_ViewportSize.x*Graphics::getWindowSize().x), (0.01f*m_ViewportSize.y*Graphics::getWindowSize().y) );

	if (m_ClearIsEnabled)
	{
		glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
		glClear(m_ClearMode);
	
	}

}

void RenderCamera::generateViewProjectionMatrix(glm::mat4x4* aViewMatrix, glm::mat4x4* aProjectionMatrix, glm::mat4x4* aVPMatrix)
{
	//VIEW
	glm::mat4x4 view;
	//view = glm::rotate(view, m_Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	//view = glm::rotate(view, m_Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	//view = glm::rotate(view, m_Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	//view = glm::mat4_cast(glm::quat(m_Rotation.x, m_Rotation.y, m_Rotation.z, m_Rotation.w));
	view = glm::mat4_cast(glm::quat(m_Rotation.w, m_Rotation.x, m_Rotation.y, m_Rotation.z));
	view = glm::rotate(view, 180.f*((float)Math::PI/180.f), glm::vec3(0.0f, 1.0f, 0.0f));//camera looks down +z
	view = glm::translate<>(view, glm::vec3(-m_Position.x, -m_Position.y, -m_Position.z));
	
	//PROJECTION
	float aspectRatio = Graphics::getWindowSize().getAspectRatio();
	glm::mat4x4 projection;

	if (aspectRatio > 0.f)
		projection = glm::perspective(glm::radians(m_FieldOfView), aspectRatio, m_NearClippingDistance, m_FarClippingDistance);

	if (aViewMatrix != 0)
		*aViewMatrix = view;
	
	if (aProjectionMatrix != 0)
		*aProjectionMatrix = projection;
	
	if (aVPMatrix != 0)
		*aVPMatrix = projection * view;

}

void RenderCamera::setClearMode(const bool &aEnabled, const ClearMode::ClearModeCode &aClearMode)
{
	m_ClearIsEnabled = aEnabled   ;
	m_ClearMode      = aClearMode ;

}
#include <Debug\Debug.h>
Math::Vector3 RenderCamera::getWorldPointFromScreenPoint(const Math::Vector2 &aScreenPoint, const float &aWorldSpaceDistance)
{
	//----
	//marshal data
	//----
	//vp dimensions
	float screenW = m_ViewportSize.x;
	float screenH = m_ViewportSize.y;
	glm::vec4 viewport = glm::vec4(0.0f, 0.0f, screenW, screenH);
	//v&p mats
	glm::mat4 tmpView;// (1.0f);
	glm::mat4 tmpProj;// = glm::perspective(90.0f, screenW / screenH, 0.1f, 1000.0f);
	generateViewProjectionMatrix(&tmpView, &tmpProj);
	//screen pos
	glm::vec3 screenPos = glm::vec3
	(
		aScreenPoint.x * m_ViewportSize.x, //denormalizing to fit glm expectation
		m_ViewportSize.y + (-1.f*aScreenPoint.y * m_ViewportSize.y), //flipping input screen pos y and denormalizing to match glm expectation
		(2 * m_NearClippingDistance) / (m_FarClippingDistance + m_NearClippingDistance - aWorldSpaceDistance * (m_FarClippingDistance - m_NearClippingDistance)) //linearizing depth
	
	);

	//calc wpos
	glm::vec3 worldPos = glm::unProject(screenPos, tmpView, tmpProj, viewport);
	//worldPos = worldPos / (worldPos.z * -1.f);

	//Debug::log(worldPos.x, ", ", worldPos.y, ", ", worldPos.z,"\n");

	return Math::Vector3
	(
		worldPos.x,
		worldPos.y,
		worldPos.z
		
	);

}