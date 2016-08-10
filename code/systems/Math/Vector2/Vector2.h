#ifndef GUAR_MATH_VECTOR2_H
#define GUAR_MATH_VECTOR2_H
/* 
 * Vector2.h
 * 
 * 
*/

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

		};

	}

}


#endif