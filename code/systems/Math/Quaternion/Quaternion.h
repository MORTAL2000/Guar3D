#ifndef GUAR_MATH_QUATERNION_H
#define GUAR_MATH_QUATERNION_H

//std inc
#include <iosfwd>

class btQuaternion;

namespace guar
{
	namespace Math
	{
		struct Vector3;

		struct Quaternion
		{
			float x, y, z, w;
			
			void setFromEuler(const Vector3 &aEulerAngles);

			Quaternion();
			Quaternion(const Vector3 &aEulerAngles);
			Quaternion(const btQuaternion &aBulletQuaternion);

			static const Quaternion Identity;

		};

		std::ostream& operator<< (std::ostream& stream, const Math::Quaternion& aQuaternion);

	}

}

#endif