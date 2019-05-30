// 
// 
// 

#include "Gameplay.h"
#include "Controls.h"

void GameplayClass::GameplayInit()
{
	Controls.ControlsInit();
}

void GameplayClass::GameplayLoop()
{
	switch (gameStateCurrent)
	{
		case GameBoot:
			
			Serial.println("Booting Up: Pinball Game Arduino...");

			gameStateCurrent = GameBegin;

		break;

		case GameBegin:

			//Setup the game
			ballAmountCurrent = 3;

			Serial.println("---===| Starting. Good Luck |===---");

			delay(150);

			gameStateCurrent = GamePlaying;

		break;

		case GamePlaying:

			InputManager();

			if (ballAmountCurrent == 0)
			{
				Serial.println("Ball Amount: " + (String)ballAmountCurrent);
				Serial.println("Dead.");
				delay(150);

				gameStateCurrent = GameEnd;
			}

		break;

		case GameEnd:

			Serial.println("---===| Game Over |===---");

			Controls.FlippersDeactivateAll();

			Serial.println("Restarting...");
			Serial.println("---------------------------");

			delay(300);

			gameStateCurrent = GameBegin;

		break;

	}
}


//---------
//- Score -
//---------

void GameplayClass::BallsAdd(int _amount)
{
	ballAmountCurrent += _amount;

	if (_amount < 0)
		Serial.println("- Lost one ball");
	else
		Serial.println("- Gained one ball");
}



//---------
//- Input -
//---------

void GameplayClass::InputManager()
{
	//- Check: Left button
	ButtonCheck(L_Button, L_Flipper);

	//- Check: Right button
	ButtonCheck(R_Button, R_Flipper);
}



bool GameplayClass::ButtonCheck(int _indexButton, int _indexFlipper)//Private
{
	bool _check = Controls.ButtonCheck(_indexButton);

	if (_check)
	{
		Controls.FlipperActivate(_indexFlipper);
	}
	else
	{
		Controls.FlipperDeactivate(_indexFlipper);
	}

	return _check;
}

bool GameplayClass::ButtonCheckPressed(int _indexButton, int _indexFlipper)
{
	bool _check = Controls.ButtonCheckPressed(_indexButton);

	if (_check)
	{
		Controls.FlipperActivate(_indexFlipper);
	}
	else
	{
		Controls.FlipperDeactivate(_indexFlipper);
	}

	return _check;
}


GameplayClass Gameplay;

