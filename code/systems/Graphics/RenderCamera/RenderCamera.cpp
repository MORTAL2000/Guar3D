#include "RenderCamera.h"

#include "../RenderTexture/RenderTexture.h"
#include "../OpenGL/OpenGL.h"
#include "../Graphics.h"

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace guar;
using namespace GFX;

RenderCamera::RenderCamera() :
	m_ClearColor(0.535f, 0.535f, 0.8f, 1.0f),
	m_RenderTexture(0)

{}

void RenderCamera::draw(void)
{
	glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
	
	RenderObserver::draw();

}

void RenderCamera::generateViewProjectionMatrix(glm::mat4x4* aViewMatrix, glm::mat4x4* aProjectionMatrix, glm::mat4x4* aVPMatrix)
{
	//VIEW
	glm::mat4x4 view;
	view = glm::rotate(view, m_Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, m_Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::rotate(view, m_Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	view = glm::translate<>(view, glm::vec3(-m_Position.x, -m_Position.y, -m_Position.z));

	//PROJECTION
	float aspectRatio = Graphics::getWindowSize().getAspectRatio();
	glm::mat4x4 projection = glm::perspective(glm::radians(m_FieldOfView), aspectRatio, m_NearClippingDistance, m_FarClippingDistance);

	if (aViewMatrix != 0)
		*aViewMatrix = view;
	
	if (aProjectionMatrix != 0)
		*aProjectionMatrix = projection;
	
	if (aVPMatrix != 0)
		*aVPMatrix = projection * view;

}