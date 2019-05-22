// Targets.h

#ifndef _TARGETS_h
#define _TARGETS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class TargetsClass
{
 public:
	 void TargetsInit();
	 
	 void TargetGroupSetup(int _index, int _pin, int _score);
	 bool TargetGroupCheckActivated(int _index);
};

extern TargetsClass Targets;

#endif

