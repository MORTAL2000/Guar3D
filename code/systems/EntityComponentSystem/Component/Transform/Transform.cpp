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
	glm::quat a(m_Rotation.w, m_Rotation.x, m_Rotation.y, m_Rotation.z);	
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
#include<Debug\Debug.h>
Math::Vector3 Transform::getEulerAngles(void)
{
	glm::quat quaternion(m_Rotation.w, m_Rotation.x, m_Rotation.y, m_Rotation.z);
	glm::vec3 euler = glm::eulerAngles(quaternion);

	Debug::log("Quat: ", m_Rotation, "Euler: ", euler.x, ", ", euler.y, ", ", euler.z, "\n");

	return Math::Vector3
	(
		euler.x,
		euler.y,
		euler.z
	
	);

}