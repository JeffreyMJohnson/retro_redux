#ifndef _MATRIX_3_H
#define _MATRIX_3_H
#include "TheMath.h"


Matrix3::Matrix3()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			matrix[row][col] = 0;
		}
	}
}

Matrix3::Matrix3(
	const float m00,
	const float m01,
	const float m02,
	const float m10,
	const float m11,
	const float m12,
	const float m20,
	const float m21,
	const float m22)
{
	matrix[0][0] = m00;
	matrix[0][1] = m01;
	matrix[0][2] = m02;
	matrix[1][0] = m10;
	matrix[1][1] = m11;
	matrix[1][2] = m12;
	matrix[2][0] = m20;
	matrix[2][1] = m21;
	matrix[2][2] = m22;
}

Matrix3::~Matrix3()
{
}

Matrix3& Matrix3::operator=(const Matrix3& rhs)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			matrix[row][col] = rhs.matrix[row][col];
		}
	}
	return *this;
}

const Matrix3 Matrix3::operator+(Matrix3& rhs)
{
	Matrix3 result = *this;
	result += rhs;
	return result;
}

Matrix3& Matrix3::operator+=(const Matrix3& rhs)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			matrix[row][col] += rhs.matrix[row][col];
		}
	}
	return *this;
}

bool Matrix3::operator==(const Matrix3& rhs)
{
	if (this == &rhs)
		return true;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (matrix[row][col] != rhs.matrix[row][col])
				return false;
		}
	}
	return true;
}

bool Matrix3::operator!=(const Matrix3& rhs)
{
	return !(*this == rhs);
}

Matrix3 Matrix3::identityMatrix;

#endif