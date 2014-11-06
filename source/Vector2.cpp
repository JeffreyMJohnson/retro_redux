#include "..\include\TheMath.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

Vector2::~Vector2()
{
}

void Vector2::operator=(Vector2& other)
{
	x = other.x;
	y = other.y;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

void Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	return Vector2(x - other.x, y - other.y);
}

void Vector2::operator-=(const Vector2& other)
{
	x -= other.x;
	y -= other.y;
}

Vector2 Vector2::operator*(const float scalar)
{
	return Vector2(x * scalar, y * scalar);
}

void Vector2::operator*=(const float scalar)
{
	x *= scalar;
	y *= scalar;
}

/*
returns true if given other Vector2 is either the same object as this or x and y are equal, else returns false
*/
bool Vector2::operator==(const Vector2& other)
{
	if (this == &other)
		return true;
	if (x == other.x && y == other.y)
		return true;
	return false;
}

//vector math functions
/*
returns magnitude of this vector
*/
float Vector2::Magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

/*
normalize this Vector2
*/
void Vector2::Normalize()
{
	float magnitude = Magnitude();
	x = x / magnitude;
	y = y / magnitude;
}

/*
return normalized Vector2 from values of this one. This vector is not changed.
*/
Vector2 Vector2::GetNormal()
{
	float mag = Magnitude();
	return Vector2(x / mag, y / mag);
}

/*
return dot product of this vector and given other vector
*/
float Vector2::DotProduct(const Vector2& other)
{
	return (x * other.x) + (y * other.y);
}

//return Vector2 perpendicular to this one
Vector2 Vector2::GetPerp()
{
	return Vector2(this->y, -this->x);
}