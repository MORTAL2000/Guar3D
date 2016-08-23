#include "Transform.h"
//math inc
#include <Math\Constants.h>
//implementation inc
#include <glm\gtc\quaternion.hpp>
#include <glm\gtx\quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
	
	//Debug::log("Quat: ", m_Rotation, "Euler: ", euler.x, ", ", euler.y, ", ", euler.z, "\n");

	return Math::Vector3
	(
		euler.x,
		euler.y,
		euler.z
	
	);

}
#include <Debug\Debug.h>
Math::Vector3 Transform::getForwardVector(void)
{
	////THE EULER METHOD ENCOUNTERS A DOMAIN PROBLEM
	//glm::vec3 euler = glm::eulerAngles(glm::quat(m_Rotation.w,m_Rotation.x,m_Rotation.y,m_Rotation.z));
	//
	////euler.y *= -1.;
	//
	//Math::Vector3 forwardVector = Math::Vector3
	//(
	//	cos(euler.y - (90.0f * Math::PI / 180))*cos(euler.x),
	//	sin(euler.x),
	//	sin(euler.y - (90.0f * Math::PI / 180))*cos(euler.x)
	//
	//) * -1.;
	//
	//Debug::log(euler.y * (180/Math::PI), "\n");
	//
	//return forwardVector;
	
	////////////////////////////////////////////////////////////////////////////
	//glm::quat quatrot(m_Rotation.w, m_Rotation.x, m_Rotation.y, m_Rotation.z);
	//glm::vec3 rotation(0, 0, 1);
	//rotation = glm::rotate<>(quatrot, rotation);
	//
	//return Math::Vector3 //d vec, with -z axis// - (90.0f * Math::PI / 180)
	//(
	//	cos(rotation.y - (90.0f * Math::PI / 180))*cos(rotation.x),
	//	sin(rotation.x),
	//	sin(rotation.y - (90.0f * Math::PI / 180))*cos(rotation.x)
	//
	//);

	return Math::Vector3
	(
		0,
		0,
		1

	);

	
}