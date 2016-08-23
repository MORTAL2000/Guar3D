#ifndef GUAR_MATH_VECTOR2_H
#define GUAR_MATH_VECTOR2_H
/* 
 * Vector2.h
 * 
 * 
*/
//std inc
#include <iosfwd>

namespace guar
{
	namespace Math
	{
		struct Vector2
		{
			float x, y;

			Vector2() : Vector2(0, 0) {}
			Vector2(const float &aX, const float &aY) { x = aX; y = aY; }

			float getAspectRatio(void) { return x / y; }

			Vector2 operator/(const Vector2 &aVector);
			Vector2 operator-(const Vector2 &aVector);

		};

		std::ostream& operator<< (std::ostream& stream, const Math::Vector2& aVector2);

	}

}


#endif