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
	Vector2 t;
	t.x += other.x;
	t.y += other.y;
	return t;
}

void Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;
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