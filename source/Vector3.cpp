#ifndef _VECTOR_3_H_
#define _VECTOR_3_H_

#include "TheMath.h"

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}

Vector3::~Vector3()
{
}

//operator overloads
void Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

void Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

void Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

Vector3 Vector3::operator*(const float scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

void Vector3::operator*=(const float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

/*
returns true if given other Vector3 is either the same object as this or x and y are equal, else returns false
*/
bool Vector3::operator==(const Vector3& other)
{
	//check if same object
	if (this == &other)
		return true;
	if (x == other.x &&
		y == other.y &&
		z == other.z)
		return true;
	return false;
}

/*
returns false if given other Vector3 is either the same object as this or x and y are equal, else returns true
*/
bool Vector3::operator!=(const Vector3& other)
{
	return !(*this == other);
}

//vector math functions
/*
returns magnitude of this vector
*/
float Vector3::Magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z,2));
}

/*
normalize this Vector3
*/
void Vector3::Normalize()
{
	float magnitude = Magnitude();
	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
}

/*
return normalized Vector3 from values of this one. This vector is not changed.
*/
Vector3 Vector3::GetNormal()
{
	Vector3 v = *this;
	v.Normalize();
	return v;
}

/*
return dot product of this vector and given other vector
*/
float Vector3::DotProduct(const Vector3& other)
{
	return (x * other.x) + (y * other.y) + (z * other.z);
}

/*
return Vector3 cross product
neither this or the given other vector are changed
*/
Vector3 Vector3::CrossProduct(const Vector3& other)
{
	//[(a2*b3) - (a3*b2), (a3*b1) - (a1*b3), (a1*b2) - (a2*b1)]
	return Vector3(
		(y * other.z) - (z * other.y),
		(z * other.x) - (x * other.z),
		(x * other.y) - (y * other.x));
}

#endif