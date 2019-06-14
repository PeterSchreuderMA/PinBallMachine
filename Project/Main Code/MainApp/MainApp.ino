/*
 Name:		JSON_PARSE_TEST.ino
 Created:	4/23/2019 12:33:30 PM
 Author:	Peter Schreuder
*/


//werkt met ArduinoJson library version 6.9.1

//pwm library https://nodemcu.readthedocs.io/en/dev/en/modules/pwm/
//#include <WiFiUdp.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecure.h>
#include <WiFiServer.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecure.h>
#include <WiFiClient.h>
#include <ESP8266WiFiType.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFi.h>
#include <CertStoreBearSSL.h>
#include <BearSSLHelpers.h>

#include "arduino.h"
#include "PinRemap.h"
#include "Internet.h"
#include "Targets.h"
#include "Gameplay.h"
#include "Controls.h"
#include "Internet.h"
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>


char* mainSsid[3] = { "Medialab", "NETGEAR_2GEXT", "WhyFy" }; // wifi lan Station ID netwerk naam [School: Medialab | Thuis: NETGEAR_2GEXT | Tel: WhyFy]
char* mainPassword[3] = { "Mediacollege", "DB67437ac17871", "harry345^" }; // wifi lan wachtwoord [School: Mediacollege | Thuis: DB67437ac17871 | Tel: harry345^]
char* mainServer = "peter-schreuder.com"; // deployment server     

String docControl = "/projecten/pinball/Website/php/dataReceiver.php"; // path to file
String docPassword = "5525";

bool canSend = false;

String stopWord = "s";

int testScore = 0;
int testScoreTimer = 0;

void setup()
{
	Serial.begin(115200);// start serial monitor 115200
	
	//- Initialize: GamePlay
	Gameplay.GameplayInit();

	int _index = 0;

	Internet.InitInternet(mainSsid[_index], mainPassword[_index], mainServer, docPassword);
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
	else
	{
		/*if (canSend != true)
			Serial.println("(Pres S to start sending)");*/
	}

	//Internet.HttpRequest(docControl);

	if (canSend)
	{
		testScoreTimer++;

		if (!testScoreTimer == testScoreTimer % 5)
			return;

		testScore++;

		//Serial.println("Send: " + String(testScore));


		Internet.HttpSend(docControl, "&score=" + String(testScore) + "&balls=" + String(testScore % 3));
	}

	Gameplay.GameplayLoop();
}
