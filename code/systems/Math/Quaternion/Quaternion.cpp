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

