/*
Retro Game
Assignment ICAPRG406A - (second assesment) for 1st year Games Programming course 10343NAT Advanced Diploma of Professional GameDevelopment
Written by Jeffrey M Johnson
jeffrey.johnson@students.aie.edu.au

This is my omage to one of the original top-down shooters Galaxian by Namco. (http://www.arcade-history.com/?n=galaxian&page=detail&id=901)

In this version you control your ship at the bottom of the screen by moving left (A key) or right (D key) and shooting at the enemy ships
(space bar).  You only have one bullet at a time to shoot with and can't shoot again until it (the bullet) hit's something or is off the screen.
The enemy ships above you will attack on a regular basis from a random direction and will rain down bullets when attacking.  How high of a score can
you get before succumbing to the enemy hoard's?

*/

#include "AIE.h"
#include "StateMachine.h"
#include "SplashScreenState.h"

using namespace std;

extern const int screenWidth = 600;
extern const int screenHeight = 800;
extern const int NUM_ENEMYS = 36;
extern const int NUM_ENEMY_COLS = 9;
extern const int NUM_ENEMY_ROWS = 4;

int main(int argc, char* argv[])
{
	Initialise(screenWidth, screenHeight, false, "Galaxian Clone");
	SetBackgroundColour(SColour(0, 0, 0, 255));

	StateMachine state;

	state.PushState(new SplashScreenState());

	//Game Loop
	do
	{
		ClearScreen();
		float delta;
		delta = GetDeltaTime();

		state.Update(delta);
		state.Draw();


	} while (!FrameworkUpdate() && !StateMachine::gameOver);


	Shutdown();

	return 0;
}
