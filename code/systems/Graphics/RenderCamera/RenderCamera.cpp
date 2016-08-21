#include "RenderCamera.h"

#include "../RenderTexture/RenderTexture.h"
#include "../OpenGL/OpenGL.h"
#include "../Graphics.h"

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

using namespace guar;
using namespace GFX;

RenderCamera::RenderCamera() : RenderObserver(), 
	m_ClearColor(0.535f, 0.535f, 0.8f, 1.0f),
	m_ViewportPosition(0, 0)
    
{}

void RenderCamera::draw(void)
{
	RenderObserver::draw();

	glViewport( m_ViewportPosition.x, m_ViewportPosition.y, (0.01f*m_ViewportSize.x*Graphics::getWindowSize().x), (0.01f*m_ViewportSize.y*Graphics::getWindowSize().y) );
	glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
	
	

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