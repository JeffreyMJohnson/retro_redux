#pragma once
#ifndef _SPLASH_SCREEN_STATE_H_
#define _SPLASH_SCREEN_STATE_H_

#include "BaseState.h"
#include "MainMenuState.h"
#include <string>

class SplashScreenState :
	public BaseState
{
public:
	SplashScreenState();
	~SplashScreenState();

	void Initialize();
	void Update(float a_timeStep, StateMachine* a_SMPointer);
	void Draw();
	void Destroy();

private:
	float splashTimer;
	float currentSplashTime;
	float dotTimer;
	float currentDotTime;
	unsigned int splashSpriteID;
	std::string loadingMsg;
	bool switchTime;
	
};

#endif