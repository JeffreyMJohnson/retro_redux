#ifndef _MAGIC_NUMBER_FACTORY_H_
#define _MAGIC_NUMBER_FACTORY_H_

/*
This is The Magic Number Factory
a class of static meber veariables to wrap global variables used in app
*/

class MNF
{
public:
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	static const int NUM_ENEMYS;
	static const int NUM_ENEMY_COLS;
	static const int NUM_ENEMY_ROWS;

	static const float BULLET_SPEED;
};

#endif