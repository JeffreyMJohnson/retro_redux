#include "..\include\MainMenuState.h"

MainMenuState::MainMenuState()
{
	key = NONE;
}


MainMenuState::~MainMenuState()
{
}

void MainMenuState::Initialize()
{
	bannerSprite = CreateSprite("./images/misc/galaxian_banner.png", (float)MNF::SCREEN_WIDTH, MNF::SCREEN_HEIGHT * .25f, true);
	MoveSprite(bannerSprite, MNF::SCREEN_WIDTH * .5f, MNF::SCREEN_HEIGHT - (MNF::SCREEN_HEIGHT * .25f) * .5f);
}
void MainMenuState::Update(float a_timeStep, StateMachine* a_SMPointer)
{
	Input();

	switch (key)
	{
	case NONE:
		break;
	case START:
		a_SMPointer->PushState(new GameState());
		break;
	case HIGH_SCORE:
		a_SMPointer->PushState(new LeaderBoardState());
		break;
	case QUIT:
		StateMachine::gameOver = true;
		a_SMPointer->PopState();
		break;
	}

}
void MainMenuState::Draw()
{
	DrawSprite(bannerSprite);
	DrawString("MAIN MENU",  MNF::SCREEN_WIDTH * .5 - 80, MNF::SCREEN_HEIGHT * .70f);
	DrawString("PRESS (S)TART NEW GAME",  MNF::SCREEN_WIDTH * .5 - 200, MNF::SCREEN_HEIGHT * .60);
	DrawString("PRESS (D)ISPLAY HIGH SCORES",  MNF::SCREEN_WIDTH * .5 - 200, MNF::SCREEN_HEIGHT * .60 - 50);
	DrawString("PRESS (Q)UIT GAME",  MNF::SCREEN_WIDTH * .5 - 200, MNF::SCREEN_HEIGHT * .60 - 100);
}
void MainMenuState::Destroy()
{

}

void  MainMenuState::Input()
{
	key = NONE;
	if (IsKeyDown(GLFW_KEY_S))
	{
		key = START;
	}

	if (IsKeyDown(GLFW_KEY_Q))
	{
		key = QUIT;
	}

	if (IsKeyDown(GLFW_KEY_D))
	{
		key = HIGH_SCORE;
	}
}