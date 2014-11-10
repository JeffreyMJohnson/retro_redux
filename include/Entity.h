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

	void SetSize(float a_width, float a_height);

	void SetPosition(float a_x, float a_y);
	void SetX(float x);
	void SetY(float y);
	Vector2 GetPosition();

	virtual void Update(float a_delta) = 0;
	virtual void Draw() = 0;

	void SetSpriteId(unsigned int a_spriteID);
	unsigned int GetSpriteID();

	void SetWidth(float a_width);
	float GetWidth();

	void SetHeight(float a_height);
	float GetHeight();

	CircleCollider collider;


	~Entity();
};
#endif // !_ENTITY_H_
