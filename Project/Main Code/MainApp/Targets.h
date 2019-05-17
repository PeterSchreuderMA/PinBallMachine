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
	void init();
};

extern TargetsClass Targets;

#endif

