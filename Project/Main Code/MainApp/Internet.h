// Internet.h

#ifndef _INTERNET_h
#define _INTERNET_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#include "ESP8266WiFi.h"
#include "ArduinoJson.h"
#else
#include "WProgram.h"
#endif

class InternetClass
{
private:
	bool debug;// print debug messages to terminal
	String docPassword;

public:
	void InitInternet(char* _ssid, char* _pw, char* _server, String _docPassword);

	void CheckConnection();
	void WifiConnect();

	void HttpRequest(String _doc);
	void HttpSend(String _file, String _data);

	void ParseJson(JsonDocument & _json_doc);
	void Payload();
	void ExtractJson();

};

extern InternetClass Internet;

#endif

