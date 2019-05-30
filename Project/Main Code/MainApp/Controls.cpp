// 
// 
// 

#include "Controls.h"
//#include <Servo.h>

//Servo flippers[2];

int leds[2];

int buttons[2];
int buttonsPrevState[2];


int flipperAngle_A = 60;// Active/
int flipperAngle_Na = 0;// Not Active



void ControlsClass::ControlsInit()
{
	debug = true;

	//- Define: Buttons
	ButtonSetup(L_Button, 14);//Left button
	ButtonSetup(R_Button, 15);//Right button

	//- Define: Flippers
	FlipperSetup(L_Flipper, 4);
	FlipperSetup(R_Flipper, 5);


	delay(10);
}

//------------
//- Flippers -
//------------

void ControlsClass::FlipperSetup(int _index, int  _pin)
{
	if (!debug)
	{
		//flippers[_index].attach(_pin);
		//FlipperRotateTo(_index, flipperAngle_Na);
	}
	else
	{
		leds[_index] = _pin;
		pinMode(leds[_index], OUTPUT);
	}
}

//Flippers
void ControlsClass::FlipperActivate(int _index)
{
	//
	if (!debug)
	{
		FlipperRotateTo(_index, flipperAngle_A);
	}
	else
	{
		digitalWrite(leds[_index], HIGH);
	}
}

void ControlsClass::FlipperDeactivate(int _index)
{
	if (!debug)
	{
		FlipperRotateTo(_index, flipperAngle_Na);
	}
	else
	{
		digitalWrite(leds[_index], LOW);
	}
}

void ControlsClass::FlippersDeactivateAll()
{
	for (size_t _i = 0; _i < sizeof(leds); _i++)
	{
		if (!debug)
		{
			FlipperRotateTo(_i, flipperAngle_Na);
		}
		else
		{
			digitalWrite(leds[_i], LOW);
		}
	}
}

void ControlsClass::FlipperRotateTo(int _index, int _angle)
{
	/*if (flippers[_index].read() != _angle)
	{
		flippers[_index].write(_angle);
		//Serial.println("Servo deactivate: " + (String)flippers[_index].read());
	}*/
}

//-----------
//- Buttons -
//-----------

void ControlsClass::ButtonSetup(int _index, int _pin)
{

	buttons[_index] = _pin;
	buttonsPrevState[_index] = HIGH;
	pinMode(buttons[_index], INPUT);
}

//Buttons
bool ControlsClass::ButtonCheck(int _index)//Checks if the button is activated
{
	bool _return = false;

	String _debugString = "--- Button: " + (String)_index + " ---";

	int _buttonState = digitalRead(buttons[_index]);//buttons[_button]

	//Check if the button is pressed
	if (_buttonState == HIGH)
		_return = true;

	delay(10);

	return _return;
}

bool ControlsClass::ButtonCheckPressed(int _index)//Checks if the button was pressed
{
	bool _return = false;

	String _debugString = "--- Button Pressed: " + (String)_index + " ---";

	int _buttonState = digitalRead(buttons[_index]);//buttons[_button]

	//Check if the button is pressed
	if (_buttonState != buttonsPrevState[_index] && _buttonState == HIGH)
		_return = true;

	buttonsPrevState[_index] = _buttonState;

	delay(10);

	return _return;
}




ControlsClass Controls;


