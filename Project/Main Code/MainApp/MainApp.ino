/*
 Name:		JSON_PARSE_TEST.ino
 Created:	4/23/2019 12:33:30 PM
 Author:	Peter Schreuder
*/


//werkt met ArduinoJson library version 6.9.1

//pwm library https://nodemcu.readthedocs.io/en/dev/en/modules/pwm/
#include "arduino.h"
#include "PinRemap.h"
#include "Internet.h"
#include "Targets.h"
#include "Gameplay.h"
#include "Controls.h"
//#include "Internet.h"
//#include <ESP8266WiFi.h>z
//#include <ArduinoJson.h>


char* mainSsid = "NETGEAR_2GEXT"; // wifi lan Station ID netwerk naam [School: Medialab | Thuis: NETGEAR_2GEXT | Tel: WhyFy]
char* mainPassword = "DB67437ac17871"; // wifi lan wachtwoord [School: Mediacollege | Thuis: DB67437ac17871 | Tel: harry345^]
char* mainServer = "peter-schreuder.com"; // deployment server     

String docControl = "/projecten/pinball/Website/php/dataReceiver.php"; // path to file

bool canSend = false;

String stopWord = "s";

void setup()
{
	Serial.begin(115200);// start serial monitor 115200
	
	//- Initialize: GamePlay
	//Gameplay.GameplayInit();

	Internet.InitInternet(mainSsid, mainPassword, mainServer);
	Internet.CheckConnection();


	delay(1);
}

void loop()
{
	String _str = "";

	//Read user input 
	_str = Serial.readString();

	if (_str != "")
	{
		if (_str == stopWord)
		{
			if (canSend != true)
			{
				canSend = true;
				Serial.println("Sending. (Pres S to stop sending)");
			}
			else
			{
				canSend = false;
				Serial.println("Stopped Sending. (Pres S to start sending)");
			}
		}
			
	}

	//Internet.HttpRequest(docControl);

	if (canSend)
		Internet.HttpSend(docControl + "?score=100");

	//Gameplay.GameplayLoop();
}
