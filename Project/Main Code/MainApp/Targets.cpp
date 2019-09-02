// 
// 
// 

#include "Targets.h"
#include "PinRemap.h"

int targetGroups[3][3];
int targetGroupsPrevState[3];

void TargetsClass::TargetsInit()
{
	//- Define: Targetgroups
	TargetGroupSetup(0, D0, 100);//First target group
	TargetGroupSetup(1, D1, 500);//First target group
	TargetGroupSetup(2, D2, 0);//First target group
}



void TargetsClass::TargetGroupSetup(int _index, int _pin, int _points)
{

	targetGroups[_index][0] = _pin;

	targetGroupsPrevState[_index] = LOW;
	pinMode(targetGroups[_index][0], INPUT);

	targetGroups[_index][1] = _points;
}

int TargetsClass::TargetScore(int _index)
{
	return targetGroups[_index][1];
}


bool TargetsClass::TargetGroupCheckActivated(int _index)//Checks if the button was pressed
{
	bool _return = false;

	

	int _buttonState = digitalRead(targetGroups[_index][0]);//buttons[_button]

	//Serial.println(_buttonState);

	//Check if the button is pressed
	if (_buttonState != targetGroupsPrevState[_index] && _buttonState == HIGH)
	{
		String _debugString = "--- Target Hit: " + (String)_index + " | +" + (String)targetGroups[_index][1] + " Score ---";

		Serial.println(_debugString);
		
		_return = true;
	}
			
	targetGroupsPrevState[_index] = _buttonState;
	

	return _return;
}

TargetsClass Targets;

