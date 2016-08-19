#include "Transform.h"

#include <glm\gtc\quaternion.hpp>

using namespace guar;
using namespace ECS;

void Transform::translate(const Math::Vector3 &aTranslation) 
{ 
	m_Position += aTranslation; 

}

void Transform::rotate(const Math::Vector3 &aRotation)
{
	//m_Rotation += aRotation;

	glm::quat a;
	a.x = m_Rotation.x;
	a.y = m_Rotation.y;
	a.z = m_Rotation.z;
	a.w = m_Rotation.w;

	glm::quat b;
	glm::rotate(b, aRotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::rotate(b, aRotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::rotate(b, aRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	a = b * a;

	m_Rotation.x = a.x;
	m_Rotation.y = a.y;
	m_Rotation.z = a.z;
	m_Rotation.w = a.w;

}