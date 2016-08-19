#include "Quaternion.h"

//external inc
#include <glm/gtc/quaternion.hpp>

using namespace guar;
using namespace Math;

Quaternion::Quaternion()
{
	//glm::quat quat;
	//
	//x = quat.x;
	//y = quat.y;
	//z = quat.z;
	//w = quat.w;

	x = 0;
	y = 0;
	z = 0;
	w = 1;

}

Quaternion::Quaternion(const Vector3 &aEulerAngles)
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

std::ostream& guar::Math::operator<< (std::ostream& stream, const Math::Quaternion& aQuaternion)
{
	stream << "{" << aQuaternion.x << ", " << aQuaternion.y << ", " << aQuaternion.z << ", " << aQuaternion.w << "}";
	return stream;

}