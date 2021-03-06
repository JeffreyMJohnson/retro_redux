#pragma once


#ifndef _BULLET_H_
#define _BULLET_H_

#include "AIE.h"
#include "Entity.h"

class Bullet : public Entity
{
public:
	int health;


	Bullet(const char* filePath, float a_width, float a_height);

	/*
	constructor to use for unit tests
	*/
	Bullet(const char* filePath, float a_width, float a_height, bool underTest);
	
	void Init(Vector2 a_pos, Vector2 a_velocity, float a_speed, float a_radius, int health);
	
	//move this bullet to given position with velocity, speed and health
	void Spawn(Vector2 a_pos, Vector2 a_velocity, float a_speed, int a_health);

	void Update(float a_delta);

	/*
	test hook function
	*/
	void Update(float a_delta, bool underTest);
	void Draw();

	friend std::ostream& operator<<(std::ostream& out, const Bullet& b);

	~Bullet();
};
#endif // !_BULLET_H_


