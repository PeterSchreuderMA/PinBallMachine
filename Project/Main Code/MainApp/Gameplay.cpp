// 
// 
// 

#include "Gameplay.h"
#include "Controls.h"
#include "Targets.h"
#include "Internet.h"

String _docControl = "/projecten/pinball/Website/php/dataReceiver.php"; // path to file

void GameplayClass::GameplayInit()
{
	Controls.ControlsInit();
	Targets.TargetsInit();
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
			scoreAmountCurrent = 0;
			ballAmountCurrent = 3;

			//- Add score
			Internet.HttpSend(_docControl, "&score=" + String(0) + "&balls=" + String(3) + "&gameState=" + String(0));

			Serial.println("---===| Starting. Good Luck |===---");

			delay(150);

			gameStateCurrent = GamePlaying;

		break;

		case GamePlaying:

			//InputManager();

			//100
			if (Targets.TargetGroupCheckActivated(0))
			{
				Serial.println("Add Score: " + Targets.TargetScore(0));

				scoreAmountCurrent += Targets.TargetScore(0);

				Serial.println("Score: " + scoreAmountCurrent);

				//- Add score
				Internet.HttpSend(_docControl, "&score=" + (String)scoreAmountCurrent);
			}
			
			
			//500
			if (Targets.TargetGroupCheckActivated(1))
			{
				Serial.println("Add Score: " + Targets.TargetScore(1));

				scoreAmountCurrent += Targets.TargetScore(1);

				Serial.println("Score: " + scoreAmountCurrent);

				//- Add score
				Internet.HttpSend(_docControl, "&score=" + String(scoreAmountCurrent));
			}

			//Gutter
			if (Targets.TargetGroupCheckActivated(2))
			{
				BallsAdd(-1);

				Serial.println("Lost a ball. Balls: " + ballAmountCurrent);
								
				//- Add score
				Internet.HttpSend(_docControl, "&balls=" + String(ballAmountCurrent));
			}
			

			if (ballAmountCurrent == 0)
			{
				Serial.println("Ball Amount: " + (String)ballAmountCurrent);
				Serial.println("Dead.");
				delay(150);

				gameStateCurrent = GameEnd;
			}

		break;

		case GameEnd:

			Internet.HttpSend(_docControl, "&gameState=" + String(1));

			Serial.println("---===| Game Over |===---");

			Controls.FlippersDeactivateAll();

			Serial.println("Restarting...");
			Serial.println("---------------------------");

			delay(4000);

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
		Serial.println("- Lost one ball, lol");
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

