#pragma once
#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <math.h>
#define PI 3.14159

enum TYPE
{
	PLAYER,
	ENEMY
};


struct Point2d
{
	float x, y;

	Point2d()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Point2d(float a_x, float a_y)
	{
		x = a_x;
		y = a_y;
	}

	inline bool operator==(const Point2d& other)
	{
		return (x == other.x && y == other.y);

	}

	inline bool operator!=(const Point2d& other)
	{
		return !(*this == other);
	}
};
#endif