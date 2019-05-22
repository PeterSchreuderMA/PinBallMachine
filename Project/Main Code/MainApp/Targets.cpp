// 
// 
// 

#include "Targets.h"

int targetGroups[2][2];
int targetGroupsPrevState[2];

void TargetsClass::TargetsInit()
{
	//- Define: Targetgroups
	TargetGroupSetup(0, 16, 100);//First text group
}



void TargetsClass::TargetGroupSetup(int _index, int _pin, int _score)
{

	targetGroups[_index][0] = _pin;
	targetGroupsPrevState[_index] = HIGH;
	pinMode(targetGroups[_index][0], INPUT);
	targetGroups[_index][1] = _score;
}


bool TargetsClass::TargetGroupCheckActivated(int _index)//Checks if the button was pressed
{
	bool _retun = false;

	String _debugString = "--- Target Hit: " + (String)_index + " | +" + (String)targetGroups[_index][1] + " Score ---";

	int _buttonState = digitalRead(targetGroups[_index][0]);//buttons[_button]

	//Check if the button is pressed
	if (_buttonState != targetGroupsPrevState[_index] && _buttonState == HIGH)
		_retun = true;

	targetGroupsPrevState[_index] = _buttonState;

	delay(10);

	return _retun;
}

TargetsClass Targets;

