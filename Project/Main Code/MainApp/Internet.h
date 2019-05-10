// Internet.h

#ifndef _INTERNET_h
#define _INTERNET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include <ESP8266WiFi.h>
	#include <ArduinoJson.h>
#else
	#include "WProgram.h"
#endif

class InternetClass
{
 protected:


 public:
	 void CheckConnection();
	 void WifiConnect();

	 void HttpRequest(String _doc);
	 void ParseJson(JsonDocument & _json_doc);
	 void Payload();
	 void ExtractJson();
	 
	 
	 
	 
	 

	void init();
};

extern InternetClass Internet;

#endif

