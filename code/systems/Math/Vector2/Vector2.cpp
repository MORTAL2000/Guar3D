#include "Vector2.h"
//std inc
#include <iostream>

using namespace guar;
using namespace Math;

std::ostream& guar::Math::operator<<(std::ostream& stream, const Math::Vector2& aVector2)
{
	stream.clear();
	stream << "{" << aVector2.x << ", " << aVector2.y << ", " << "}";
	return stream;
}

Vector2 Vector2::operator/(const Vector2 &aVector)
{
	return Vector2
	(
		x / aVector.x,
		y / aVector.y

	);

}

Vector2 Vector2::operator-(const Vector2 &aVector)
{
	return Vector2
	(
		x - aVector.x,
		y - aVector.y

	);

}