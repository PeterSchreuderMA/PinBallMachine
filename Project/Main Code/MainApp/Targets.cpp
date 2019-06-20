// 
// 
// 

#include "Targets.h"
#include "PinRemap.h"

int targetGroups[2][2];
int targetGroupsPrevState[2];

void TargetsClass::TargetsInit()
{
	//- Define: Targetgroups
	TargetGroupSetup(0, PinRemap.D0, 100);//First target group
}



void TargetsClass::TargetGroupSetup(int _index, int _pin, int _points)
{

	targetGroups[_index][0] = _pin;

	targetGroupsPrevState[_index] = HIGH;
	pinMode(targetGroups[_index][0], INPUT);

	targetGroups[_index][1] = _points;
}

int TargetsClass::TargetScore(int _index)
{
	return targetGroups[_index][1];
}


bool TargetsClass::TargetGroupCheckActivated(int _index)//Checks if the button was pressed
{
	bool _retun = false;

	

	int _buttonState = digitalRead(targetGroups[_index][0]);//buttons[_button]

	Serial.println(_buttonState);

	//Check if the button is pressed
	if (_buttonState != targetGroupsPrevState[_index] && _buttonState == HIGH)
	{
		String _debugString = "--- Target Hit: " + (String)_index + " | +" + (String)targetGroups[_index][1] + " Score ---";

		Serial.println(_debugString);
		
		_retun = true;
	}
		

	targetGroupsPrevState[_index] = _buttonState;

	delay(10);

	return _retun;
}

TargetsClass Targets;

