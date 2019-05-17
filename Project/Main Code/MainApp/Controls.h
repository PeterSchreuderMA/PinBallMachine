// Controls.h

#ifndef _CONTROLS_h
#define _CONTROLS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum Flippers { L_Flipper, R_Flipper };
enum Buttons { L_Button, R_Button };

class ControlsClass
{
 public:
	 void ControlsInit();
	 
	 void FlipperSetup(int _index, int  _pin);
	 void FlipperActivate(int _index);
	 void FlipperDeactivate(int _index);
	 void FlippersDeactivateAll();
	 void FlipperRotateTo(int _index, int _angle);
	 
	 void ButtonSetup(int _index, int _pin);
	 bool ButtonCheck(int _index);
	 bool ButtonCheckPressed(int _index);
};

extern ControlsClass Controls;

#endif

