#include "Vector3.h"

//math inc
#include <math.h>
//Implementation inc
#include <Bullet\btBulletDynamicsCommon.h>
//std inc
#include <iostream>

using namespace guar;
using namespace Math;

//static const
const Vector3 Vector3::Up       = Vector3( 0.f, 1.f, 0.f);
const Vector3 Vector3::Down     = Vector3( 0.f,-1.f, 0.f);
const Vector3 Vector3::Left     = Vector3(-1.f, 0.f, 0.f);
const Vector3 Vector3::Right    = Vector3( 1.f, 0.f, 0.f);
const Vector3 Vector3::Forward  = Vector3( 0.f, 0.f, 1.f);
const Vector3 Vector3::Backward = Vector3( 0.f, 0.f,-1.f);
const Vector3 Vector3::Zero     = Vector3( 0.f, 0.f, 0.f);

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

void Vector3::operator-=(const Vector3 &aVector)
{
	x -= aVector.x;
	y -= aVector.y;
	z -= aVector.z;

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

std::ostream& guar::Math::operator<<(std::ostream& stream,const Math::Vector3& aVector3)
{
	stream.clear();
	stream << "{" << aVector3.x << ", " << aVector3.y << ", " << aVector3.z << "}";
	return stream;
}

Vector3::Vector3(const btVector3 &aBulletVector)
{
	x = aBulletVector.getX();
	y = aBulletVector.getY();
	z = aBulletVector.getZ();

}