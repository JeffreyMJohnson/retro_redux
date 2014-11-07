
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
	Vector2& operator=(const Vector2& rhs);

	Vector2 operator+(const Vector2& other);
	Vector2& Vector2::operator+=(const Vector2& rhs);

	Vector2 operator-(const Vector2& other);
	void operator-=(const Vector2& other);

	Vector2 operator*(const float scalar);
	void operator*=(const float scalar);

	/*
	returns true if given other Vector2 is either the same object as this or x and y are equal, else returns false
	*/
	bool operator==(const Vector2& other);

	/*
	returns false if given other Vector2 is either the same object as this or x and y are equal, else returns true
	*/
	bool operator!=(const Vector2& other);

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

class Vector3
{
public:
	Vector3();
	Vector3(float a_x, float a_y, float a_z);

	~Vector3();

	float x, y, z;

	//operator overloads
	void operator=(const Vector3& other);

	Vector3 operator+(const Vector3& other);
	void operator+=(const Vector3& other);

	Vector3 operator-(const Vector3& other);
	void operator-=(const Vector3& other);

	Vector3 operator*(const float scalar);
	void operator*=(const float scalar);

	/*
	returns true if given other Vector3 is either the same object as this or x and y are equal, else returns false
	*/
	bool operator==(const Vector3& other);

	/*
	returns false if given other Vector3 is either the same object as this or x and y are equal, else returns true
	*/
	bool operator!=(const Vector3& other);

	//vector math functions
	/*
	returns magnitude of this vector
	*/
	float Magnitude();

	/*
	normalize this Vector3
	*/
	void Normalize();

	/*
	return normalized Vector3 from values of this one. This vector is not changed.
	*/
	Vector3 GetNormal();

	/*
	return dot product of this vector and given other vector
	*/
	float DotProduct(const Vector3& other);

	/*
	return Vector3 cross product
	neither this or the given other vector are changed
	*/	
	Vector3 CrossProduct(const Vector3& other);

	//need LERP function when cover that

};

/*
3X3 Matrix
*/
class Matrix3
{
public:
	Matrix3();
	Matrix3(
		const float m00,
		const float m01,
		const float m02,
		const float m10,
		const float m11,
		const float m12,
		const float m20,
		const float m21,
		const float m22);
	~Matrix3();

	//builds and returns a new identity matrix 
	static Matrix3& Identity()
	{
		Matrix3 m = Matrix3();
		m.matrix[0][0] = 1;
		m.matrix[0][1] = 0;
		m.matrix[0][2] = 0;

		m.matrix[1][0] = 0;
		m.matrix[1][1] = 1;
		m.matrix[1][2] = 0;

		m.matrix[2][0] = 0;
		m.matrix[2][1] = 0;
		m.matrix[2][2] = 1;
		return m;
	}

	//transposes this matrix
	Matrix3& Transpose();

	//returns a matrix3 the transpose of this. This matrix does not change
	Matrix3 GetTranspose();

	Matrix3 operator+(Matrix3& other);
	Matrix3 operator-(Matrix3& other);
	Matrix3 operator*(Matrix3& other);
	Matrix3 operator*(Vector3& other);

	Matrix3& operator+=(Matrix3& other);
	Matrix3& operator-=(Matrix3& other);
	Matrix3& operator*=(Matrix3& other);

	bool operator==(const Matrix3& rhs);
	bool operator!=(const Matrix3& rhs);

	float matrix[3][3];
};

#endif
