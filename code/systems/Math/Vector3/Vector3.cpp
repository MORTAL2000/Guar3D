#include "Vector3.h"

//projinc
#include <math.h>

using namespace guar;
using namespace Math;

//static const
const Vector3 Vector3::Up       = Vector3( 0.0f, 1.0f, 0.0f);
const Vector3 Vector3::Down     = Vector3( 0.0f,-1.0f, 0.0f);
const Vector3 Vector3::Left     = Vector3(-1.0f, 0.0f, 0.0f);
const Vector3 Vector3::Right    = Vector3( 1.0f, 0.0f, 0.0f);
const Vector3 Vector3::Forward  = Vector3( 0.0f, 0.0f, 1.0f);
const Vector3 Vector3::Backward = Vector3( 0.0f, 0.0f,-1.0f);
const Vector3 Vector3::Zero     = Vector3(0.0f, 0.0f,  0.0f);

//ctors
Vector3::Vector3(const float &aX, const float &aY, const float &aZ) : x(aX), y(aY), z(aZ) {}
Vector3::Vector3(const float &aScalar) : x(aScalar), y(aScalar), z(aScalar) {}
Vector3::Vector3() : x(0), y(0), z(0) {}

//operators
Vector3 Vector3::operator+(const Vector3 &aVector)
{
	return Vector3(aVector.x + x, aVector.y + y, aVector.z + z);

}

Vector3 Vector3::operator-(const Vector3 &aVector)
{
	return Vector3(aVector.x - x, aVector.y - y, aVector.z - z);

}

void Vector3::operator+=(const Vector3 &aVector)
{
	x += aVector.x;
	y += aVector.y;
	z += aVector.z;

}

Vector3 Vector3::operator*(const float &aScalar)
{
	return Vector3
	(
		x * aScalar,
		y * aScalar,
		z * aScalar

	);

}

Vector3 Vector3::operator*(const float &aScalar) const
{
	return Vector3
	(
		x * aScalar,
		y * aScalar,
		z * aScalar

	);


}

void Vector3::operator*=(const float &aScalar)
{
	x *= aScalar;
	y *= aScalar;
	z *= aScalar;

}

float Vector3::length(void)
{
	return sqrt( (x*x) + (y*y) + (z*z) );

}
#include <iostream>
void Vector3::normalize(void)
{
	float magnitude = Vector3::length();

	std::cout << "Magnitude: " << magnitude << "\n";

	if (magnitude == 0.0f) // n/0 case
		return;
	
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;

}

void Vector3::normalizeAndScale(const float &aScalar)
{
	normalize();
	operator*=(aScalar);

}