#pragma once

#ifndef _PLAYER_H_
#define  _PLAYER_H_

#include "Entity.h"
#include "Utility.h"
#include "BulletManager.h"

class Player : public Entity
{
public:
	unsigned int spriteID_A;
	unsigned int spriteID_B;
	int health;
	
	//Instantiate player with sprite
	Player(char* filePath, float a_width, float a_height);

	/*
	test hooks
	*/
	Player(char* filePath, float a_width, float a_height, bool underTest);

	//initialize player with position, velocity, radius (collider),health, speed and alive
	void Init(Vector2 a_pos, Vector2 a_velocity, float a_radius, int a_health);

	//input handling
	void Input();

	/*
	test hook
	*/
	void Input(bool leftKeyDown, bool rightKeyDown, bool shootKeyDown, bool playerBulletAlive);

	//handle shooting
	void Shoot();

	//Must implement these methods before can instantiate class
	void Update(float a_delta);
	void Draw();

	friend std::ostream& operator<<(std::ostream& out, const Player& p);

	~Player();
};


#endif // _PLAYER_H_