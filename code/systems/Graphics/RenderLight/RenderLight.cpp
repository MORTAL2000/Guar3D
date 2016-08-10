#include "RenderLight.h"
#include "../OpenGL/OpenGL.h"
#include "../Graphics.h"

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <math.h>

using namespace guar;
using namespace GFX;

void RenderLight::draw(void)
{
	RenderObserver::draw();



}

RenderLight::RenderLight()
{
	m_RenderTexture = Graphics::getRenderTexture();

}

void RenderLight::generateViewProjectionMatrix(glm::mat4x4* aViewMatrix, glm::mat4x4* aProjectionMatrix, glm::mat4x4* aVPMatrix)
{
	////VIEW
	//glm::mat4x4 view;
	//view = glm::rotate(view, m_Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	//view = glm::rotate(view, m_Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	//view = glm::rotate(view, m_Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	//view = glm::translate<>(view, glm::vec3(-m_Position.x, -m_Position.y, -m_Position.z));
	//
	////PROJECTION
	//float aspectRatio = Graphics::getWindowSize().getAspectRatio();
	//glm::mat4x4 projection = glm::ortho<float>(-10, 10, -10, 10, 0, 100); //glm::perspective(glm::radians(m_FieldOfView), aspectRatio, m_NearClippingDistance, m_FarClippingDistance);

	/////////////////////////////////////////////////////////////////////

	////VIEW
	glm::mat4x4 view;
	view = glm::rotate(view, m_Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, m_Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::rotate(view, m_Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	view = glm::translate<>(view, glm::vec3(-m_Position.x, -m_Position.y, -m_Position.z));
	//
	////PROJECTION
	//float aspectRatio = Graphics::getWindowSize().getAspectRatio();
	//glm::mat4x4 projection = glm::perspective(glm::radians(m_FieldOfView), aspectRatio, m_NearClippingDistance, m_FarClippingDistance);


	////////////////////////////////////////////////////////////
	//glm::vec3 lightInvDir = glm::vec3(100, 100, 100);
	//glm::mat4 view = glm::lookAt(lightInvDir, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	glm::mat4 projection = glm::ortho<float>(-100, 100, -100, 100, -10, 1000);
	

	if (aViewMatrix != 0)
		*aViewMatrix = view;

	if (aProjectionMatrix != 0)
		*aProjectionMatrix = projection;

	if (aVPMatrix != 0)
		*aVPMatrix = projection * view;

}