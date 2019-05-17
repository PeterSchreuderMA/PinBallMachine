// 
// 
// 

#include "MachineServos.h"
#include <Servo.h>

Servo servo;

void MachineServosClass::InitServos()
{
	servo.attach(4);
	servo.write(0);
	delay(1);
}

void MachineServosClass::TestServos()
{
	servo.write(90);
	delay(1000);
	servo.write(0);
	delay(1000);
}




MachineServosClass MachineServos;

