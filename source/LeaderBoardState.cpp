#include "..\include\LeaderBoardState.h"

//extern const int screenWidth;
//extern const int screenHeight;

LeaderBoardState::LeaderBoardState()
{
}


LeaderBoardState::~LeaderBoardState()
{
}

void LeaderBoardState::Initialize()
{
	bannerSprite = CreateSprite("./images/misc/galaxian_banner.png", (float) MNF::SCREEN_WIDTH, MNF::SCREEN_HEIGHT * .25f, true);
	MoveSprite(bannerSprite,  MNF::SCREEN_WIDTH * .5f, MNF::SCREEN_HEIGHT - (MNF::SCREEN_HEIGHT * .25f) * .5f);

	HighScores hScores;
	hScores.LoadScores();
	scores = hScores.GetScores();
	goBack = false;
}
void LeaderBoardState::Update(float a_timeStep, StateMachine* a_SMPointer)
{
	Input();
	if (goBack)
	{
		a_SMPointer->PopState();
	}
}
void LeaderBoardState::Draw()
{
	DrawSprite(bannerSprite);
	DrawString("HIGH SCORES",  MNF::SCREEN_WIDTH * .5f - 100, MNF::SCREEN_HEIGHT * .70f);
	float yPos = MNF::SCREEN_HEIGHT * .65f;
	float xPos =  MNF::SCREEN_WIDTH * .5f - 50;

	for (std::list<int>::iterator it = scores.begin(); it != scores.end(); it++)
	{
		char s[10];
		//sprintf(s, "%5d", *it);
		sprintf_s(s, "%5d", *it);
		DrawString(s, xPos, yPos);
		yPos -= 35;
	}

	DrawString("PRESS <ESC> TO RETURN TO MAIN MENU",  MNF::SCREEN_WIDTH * .5 - 280, MNF::SCREEN_HEIGHT * .1);
}
void LeaderBoardState::Destroy()
{

}

void  LeaderBoardState::Input()
{
	if (IsKeyDown(GLFW_KEY_ESCAPE))
	{
		goBack = true;
	}
}