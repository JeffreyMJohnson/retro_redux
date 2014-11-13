#include "MNF.h"

//global constants
const int MNF::SCREEN_WIDTH = 600;
const int MNF::SCREEN_HEIGHT = 800;
const int MNF::NUM_ENEMYS = 36;
const int MNF::NUM_ENEMY_COLS = 9;
const int MNF::NUM_ENEMY_ROWS = 4;

//Gamestate
//UI data
const char* MNF::SCORE_LABEL = "1UP";
const Vector2 MNF::SCORE_POSITION = Vector2(MNF::SCREEN_WIDTH * .1f, MNF::SCREEN_HEIGHT);
const char* MNF::HIGH_SCORE_LABEL = "HIGH SCORE";
const Vector2 MNF::HIGH_SCORE_POSITION = Vector2(MNF::SCREEN_WIDTH * .5f - 75.0f, MNF::SCREEN_HEIGHT);

//player extra life data
const Vector2 MNF::PLAYER_LIFE_TEXTURE_SIZE = Vector2(35.0f, 41.0f);

//player data
const Vector2 MNF::PLAYER_SIZE = Vector2(46.0f, 69.0f);
const Vector2 MNF::PLAYER_INITIAL_POSITION = Vector2(MNF::SCREEN_WIDTH * 0.5f, 100.0f);
const float MNF::PLAYER_SPEED = 25.0f;
const float MNF::RESTART_TIMER = 5.0f;

//enemy group
const float MNF::ENEMY_GROUP_SPEED = 20.0f;

const float MNF::BULLET_SPEED = 100.0f;
