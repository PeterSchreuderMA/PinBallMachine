// Internet.h

#ifndef _INTERNET_h
#define _INTERNET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class InternetClass
{
 public:
	 void InternetSetup();
	 void InternetCheckSend();
	 String InternetSendData(String _command, const int _timeout, boolean _debug);
};

extern InternetClass Internet;

#endif

