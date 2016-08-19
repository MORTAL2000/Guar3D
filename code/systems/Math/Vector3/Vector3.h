#ifndef GUAR_MATH_VECTOR3_H
#define GUAR_MATH_VECTOR3_H
/* 
 * Vector3
 * 
*/
//std inc
#include <iosfwd>

namespace guar
{
	namespace Math
	{
		struct Vector3
		{
			float x, y, z;

			Vector3(const float &aX, const float &aY, const float &aZ);
			Vector3(const float &aScalar);
			Vector3();

			float length(void);
			void normalize(void);
			void normalizeAndScale(const float &aScalar);

			Vector3 operator+(const Vector3 &aVector);
			Vector3 operator-(const Vector3 &aVector);
			void operator+=(const Vector3 &aVector);
			Vector3 operator*(const float &aScalar);
			Vector3 operator*(const float &aScalar) const;
			void operator*=(const float &aScalar);
			

			static const Vector3 Up;
			static const Vector3 Down;
			static const Vector3 Left;
			static const Vector3 Right;
			static const Vector3 Forward;
			static const Vector3 Backward;
			static const Vector3 Zero;

		};

		std::ostream& operator<< (std::ostream& stream, const Math::Vector3& aVector3);

	}

}

#endif