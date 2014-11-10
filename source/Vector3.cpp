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

/*this static function returns a Vector3 representing the given index (zero based) row or column of the given matrix parameter depending
on the given MATRIX_MAJOR enum type.
(e.g.
Matrix3 MyVector(
1, 2, 3,
4, 5, 6,
7, 8, 9);
Vector3::GetVector3(ROW, 1, MyMatrix); returns a Vector3 representing the second row of MyMatrix => (4, 5, 6)
Vector3::GetVector3(COL, 0, MyMatrix); returns a Vector3 representing the first column of MyMatrix => (1, 4, 7))
*/
const Vector3 Vector3::GetVector3(MATRIX_MAJOR type, int index, const Matrix3& matrix)
{
	float x, y, z;
	if (type == ROW)
	{
		x = matrix.matrix[index][0];
		y = matrix.matrix[index][1];
		z = matrix.matrix[index][2];
	}
	else
	{
		x = matrix.matrix[0][index];
		y = matrix.matrix[1][index];
		z = matrix.matrix[2][index];
	}
	return Vector3(x, y, z);
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

std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
	out << "Vector3 [x: " << v.x << " y: " << v.y << " z: " << v.z << "]";
	return out;
}

//vector math functions
/*
returns magnitude of this vector
*/
float Vector3::Magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
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