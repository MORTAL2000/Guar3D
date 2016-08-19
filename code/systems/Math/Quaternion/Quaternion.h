#ifndef GUAR_MATH_QUATERNION_H
#define GUAR_MATH_QUATERNION_H

#include "../Vector3/Vector3.h"

namespace guar
{
	namespace Math
	{
		struct Quaternion
		{
			float x, y, z, w;
			
			Quaternion();
			Quaternion(const Vector3 &aEulerAngles);

		};

		std::ostream& operator<< (std::ostream& stream, const Math::Quaternion& aQuaternion);

	}

}

#endif