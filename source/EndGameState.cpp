#include "..\include\EndGameState.h"

EndGameState::EndGameState()
{
}


EndGameState::~EndGameState()
{
}

void EndGameState::Initialize()
{
	returnToMenu = false;
}

void EndGameState::Update(float a_timeStep, StateMachine* a_SMPointer)
{
	Input();
	if (returnToMenu)
	{
		a_SMPointer->PopState();
	}
}

void EndGameState::Draw()
{
	DrawString("GAME OVER",  MNF::SCREEN_WIDTH * 0.5f - 100, MNF::SCREEN_HEIGHT * .75f);

	DrawString("SCORE",  MNF::SCREEN_WIDTH * .25, MNF::SCREEN_HEIGHT * .50);
	char score[10];
	sprintf_s(score, "%05d", BaseState::score);
	DrawString(score,  MNF::SCREEN_WIDTH *0.5 + 50, MNF::SCREEN_HEIGHT * .50);

	DrawString("PRESS <ESC> TO RETURN TO MAIN MENU",  MNF::SCREEN_WIDTH * .5 - 280, MNF::SCREEN_HEIGHT * .1);
}

void EndGameState::Destroy()
{

}

//PRIVATE FUNCTIONS
void EndGameState::Input()
{
	if (IsKeyDown(GLFW_KEY_ESCAPE))
	{
		returnToMenu = true;
	}
}