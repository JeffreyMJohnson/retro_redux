#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "TheMath.h"
#include "Utility.h"
#include "CircleCollider.h"

extern const int screenWidth;
extern const int screenHeight;

class Entity
{
public:

	unsigned int spriteID;
	float width;
	float height;
	Point2d velocity;
	Vector2 position;
	//speed with direction. could refactor to speed scalar (magnitude) and unit Vector direction.
	//Vector2 velocity;
	float speed;
	bool alive;

	Entity();

	virtual void Update(float a_delta) = 0;
	virtual void Draw() = 0;

	CircleCollider collider;


	~Entity();
};
#endif // !_ENTITY_H_
