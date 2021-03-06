#pragma once
#ifndef _CIRCLE_COLLIDER_H_
#define _CIRCLE_COLLIDER_H_

#include "TheMath.h"

class CircleCollider
{
public:
	float radius;
	Vector2 center;

	CircleCollider();
	CircleCollider(float a_radius, Vector2 a_center);
	~CircleCollider();

	friend std::ostream& operator<<(std::ostream& out, const CircleCollider& c);

	/*
	return true if given other parameter position is within distance of this Entity position
	within both object's set collision distance. otherwise will return false.
	//make sure you set the collisionDx variable in each object before calling this function;
	uses circle collider algorithm -> the collision formula is (x2 - x1)^2 + (y2 - y1)^2 <= (r1 + r2)^2
	*/
	bool isCollided(CircleCollider &other);
};


#endif
