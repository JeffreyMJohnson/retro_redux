#ifndef _MAGIC_NUMBER_FACTORY_H_
#define _MAGIC_NUMBER_FACTORY_H_

#include "TheMath.h"

/*
This is The Magic Number Factory
a class of static meber veariables to wrap global variables used in app
*/

class MNF
{
public:
	//global constants
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	static const int NUM_ENEMYS;
	static const int NUM_ENEMY_COLS;
	static const int NUM_ENEMY_ROWS;

	//gamestate
	//UI data
	static const char* SCORE_LABEL;
	static const Vector2 SCORE_POSITION;
	static const char* HIGH_SCORE_LABEL;
	static const Vector2 HIGH_SCORE_POSITION;

	//player extra life data
	static const Vector2 PLAYER_LIFE_TEXTURE_SIZE;

	//player data
	static const Vector2 PLAYER_SIZE;
	static const Vector2 PLAYER_INITIAL_POSITION;
	static const float PLAYER_SPEED;
	static const float RESTART_TIMER;

	//enemy group
	static const float ENEMY_GROUP_SPEED;

	static const float BULLET_SPEED;
};

#endif