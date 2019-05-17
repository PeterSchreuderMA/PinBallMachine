/*
 Name:		JSON_PARSE_TEST.ino
 Created:	4/23/2019 12:33:30 PM
 Author:	Peter Schreuder
*/


//werkt met ArduinoJson library version 6.9.1

//pwm library https://nodemcu.readthedocs.io/en/dev/en/modules/pwm/
#include "Internet.h"
#include "Targets.h"
#include "Gameplay.h"
#include "Controls.h"
#include "MachineServos.h"
//#include "Internet.h"
//#include <ESP8266WiFi.h>
//#include <ArduinoJson.h>


char* mainSsid = "Medialab"; // wifi lan Station ID netwerk naam [School: Medialab | Thuis: NETGEAR_2GEXT | Tel: WhyFy]
char* mainPassword = "Mediacollege"; // wifi lan wachtwoord [School: Mediacollege | Thuis: DB67437ac17871 | Tel: harry345^]
char* mainServer = "gamereach.nl"; // deployment server

String docControl = "/control.json"; // path to file



void setup()
{
	Serial.begin(115200);// start serial monitor 115200
	
	//- Initialize: GamePlay
	Gameplay.GameplayInit();
	
	delay(1);
}

void loop()
{
	Gameplay.GameplayLoop();
}
