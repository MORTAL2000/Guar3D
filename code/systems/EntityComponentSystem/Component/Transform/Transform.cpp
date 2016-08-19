#include "Transform.h"

#include <glm\gtc\quaternion.hpp>
#include <glm\vec3.hpp>

using namespace guar;
using namespace ECS;

void Transform::translate(const Math::Vector3 &aTranslation) 
{ 
	m_Position += aTranslation; 

}

void Transform::rotate(const Math::Vector3 &aRotation)
{
	glm::quat a;
	a.x = m_Rotation.x;
	a.y = m_Rotation.y;
	a.z = m_Rotation.z;
	a.w = m_Rotation.w;

	//a = glm::rotate(a, aRotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	//a = glm::rotate(a, 0.001f, glm::vec3(0.0f, 1.0f, 0.0f));
	//a = glm::rotate(a, aRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	
	//a = x * a;
	
	glm::quat b(glm::vec3(aRotation.x,aRotation.y,aRotation.z));
	a = b* a;

	m_Rotation.x = a.x;
	m_Rotation.y = a.y;
	m_Rotation.z = a.z;
	m_Rotation.w = a.w;

}

void Transform::setRotation(const Math::Vector3 &aEulerAngles)
{
	m_Rotation.setFromEuler(aEulerAngles);

}