#ifndef GUAR_MATH_QUATERNION_H
#define GUAR_MATH_QUATERNION_H

//math inc
#include "../Vector3/Vector3.h"
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
			Math::Vector3 getEuler(void);

			Quaternion();
			Quaternion(const Vector3 &aEulerAngles);
			Quaternion(const btQuaternion &aBulletQuaternion);
			Quaternion(const float &aX, const float &aY, const float &aZ, const float &aW);

			static const Quaternion Identity;

		};

		std::ostream& operator<< (std::ostream& stream, const Math::Quaternion& aQuaternion);

	}

}

#endif