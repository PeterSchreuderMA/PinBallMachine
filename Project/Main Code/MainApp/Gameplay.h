// Gameplay.h

#ifndef _GAMEPLAY_h
#define _GAMEPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum GameStates { GameBoot, GameBegin, GamePlaying, GameEnd };

class GameplayClass
{
 private:
	 bool ButtonCheck(int _indexButton, int _indexFlipper);
	 bool ButtonCheckPressed(int _indexButton, int _indexFlipper);


 public:
	 int ballAmountCurrent;


	 //- Set: Gamestate
	 GameStates gameStateCurrent = GameBoot;

	void GameplayInit();
	void GameplayLoop();

	void InputManager();

	void BallsAdd(int _amount);
};

extern GameplayClass Gameplay;

#endif

