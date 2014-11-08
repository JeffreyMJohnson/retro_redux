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

//transposes this matrix
Matrix3& Matrix3::Transpose()
{
	Matrix3 result;
	for (int row = 0; row < 3; row++)
	{
		//get the row'th column from this object
		Vector3 v = Vector3::GetVector3(COL, row, *this);
		//set the temp matrix's row'th row to the vector's values
		result.matrix[row][0] = v.x;
		result.matrix[row][1] = v.y;
		result.matrix[row][2] = v.z;
	}
	*this = result;
	return *this;	
}

//returns a matrix3 the transpose of this. This matrix does not change
Matrix3 Matrix3::GetTranspose()
{
	Matrix3 result = *this;
	result.Transpose();
	return result;
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

const Matrix3 Matrix3::operator+(const Matrix3& rhs)
{
	Matrix3 result = *this;
	result += rhs;
	return result;
}

const Matrix3 Matrix3::operator-(const Matrix3& rhs)
{
	Matrix3 result = *this;
	result -= rhs;
	return result;
}

const Matrix3 Matrix3::operator*(const Matrix3& rhs)
{
	Matrix3 result = *this;
	result *= rhs;
	return result;
}

const Vector3 Matrix3::operator*(const Vector3& rhs)
{
	Vector3 result;
	Vector3 row = Vector3::GetVector3(ROW, 0, *this);
	result.x = row.DotProduct(rhs);
	row = Vector3::GetVector3(ROW, 1, *this);
	result.y = row.DotProduct(rhs);
	row = Vector3::GetVector3(ROW, 2, *this);
	result.z = row.DotProduct(rhs);
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

Matrix3& Matrix3::operator-=(const Matrix3& rhs)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			matrix[row][col] -= rhs.matrix[row][col];
		}
	}
	return *this;
}

Matrix3& Matrix3::operator*=(const Matrix3& rhs)
{
	//need to use a temp because use the object during the process and can't modify during.
	Matrix3 result;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			Vector3 rowVector = Vector3::GetVector3(ROW, row, *this);
			Vector3 colVector = Vector3::GetVector3(COL, col, rhs);
			result.matrix[row][col] = rowVector.DotProduct(colVector);
		}
	}
	return *this = result;
}

const bool Matrix3::operator==(const Matrix3& rhs)
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

const bool Matrix3::operator!=(const Matrix3& rhs)
{
	return !(*this == rhs);
}

Matrix3 Matrix3::identityMatrix;

#endif