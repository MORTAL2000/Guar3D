#include "Quaternion.h"

//math inc
#include "../Vector3/Vector3.h"
//implementation inc
#include <glm/gtc/quaternion.hpp>
#include <Bullet\btBulletDynamicsCommon.h>
//std inc
#include <iostream>

using namespace guar;
using namespace Math;

const Quaternion Quaternion::Identity = Quaternion();

Quaternion::Quaternion() : x(0.), y(0.), z(0.), w(1.)
{}

Quaternion::Quaternion(const Vector3 &aEulerAngles)
{
	setFromEuler(aEulerAngles);

}

void Quaternion::setFromEuler(const Vector3 &aEulerAngles)
{
	glm::quat quat;
	quat = glm::rotate(quat, aEulerAngles.x, glm::vec3(1.0f, 0.0f, 0.0f));
	quat = glm::rotate(quat, aEulerAngles.y, glm::vec3(0.0f, 1.0f, 0.0f));
	quat = glm::rotate(quat, aEulerAngles.z, glm::vec3(0.0f, 0.0f, 1.0f));

	x = quat.x;
	y = quat.y;
	z = quat.z;
	w = quat.w;

}

Math::Vector3 Quaternion::getEuler(void)
{
	glm::quat quaternion(w, x, y, z);
	glm::vec3 euler = glm::eulerAngles(quaternion);

	//Debug::log("Quat: ", m_Rotation, "Euler: ", euler.x, ", ", euler.y, ", ", euler.z, "\n");

	return Math::Vector3
	(
		euler.x,
		euler.y,
		euler.z

	);

}

Quaternion::Quaternion(const btQuaternion &aBulletQuaternion)
{
	x = aBulletQuaternion.getX();
	y = aBulletQuaternion.getY();
	z = aBulletQuaternion.getZ();
	w = aBulletQuaternion.getW();

}

std::ostream& guar::Math::operator<< (std::ostream& stream, const Math::Quaternion& aQuaternion)
{
	stream << "{" << aQuaternion.x << ", " << aQuaternion.y << ", " << aQuaternion.z << ", " << aQuaternion.w << "}";
	return stream;

}

Quaternion::Quaternion(const float &aX, const float &aY, const float &aZ, const float &aW)
{
	x = aX;
	y = aY;
	z = aZ;
	w = aW;

}