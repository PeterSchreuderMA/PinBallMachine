// MachineServos.h

#ifndef _MACHINESERVOS_h
#define _MACHINESERVOS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MachineServosClass
{
 public:
	void InitServos();
	void TestServos();
};

extern MachineServosClass MachineServos;

#endif

