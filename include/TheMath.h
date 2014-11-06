
#pragma once
#ifndef _THE_MATH_H_
#define _THE_MATH_H_

#include <math.h>

class Vector2
{
public:
	Vector2();
	Vector2(float a_x, float a_y);

	~Vector2();

	float x, y;

	//operator overloads
	void operator=(Vector2& other);

	Vector2 operator+(const Vector2& other);
	void operator+=(const Vector2& other);

	Vector2 operator-(const Vector2& other);
	void operator-=(const Vector2& other);

	Vector2 operator*(const float scalar);
	void operator*=(const float scalar);

	/*
	returns true if given other Vector2 is either the same object as this or x and y are equal, else returns false
	*/
	bool operator==(const Vector2& other);

	//vector math functions
	/*
	returns magnitude of this vector
	*/
	float Magnitude();

	/*
	normalize this Vector2
	*/
	void Normalize();

	/*
	return normalized Vector2 from values of this one. This vector is not changed.
	*/
	Vector2 GetNormal();

	/*
	return dot product of this vector and given other vector
	*/
	float DotProduct(const Vector2& other);

	//return Vector2 perpendicular to this one
	Vector2 GetPerp();

	//need LERP function when cover that

};

#endif
