/*
 Name:		JSON_PARSE_TEST.ino
 Created:	4/23/2019 12:33:30 PM
 Author:	Peter Schreuder
*/


//werkt met ArduinoJson library version 6.9.1

//pwm library https://nodemcu.readthedocs.io/en/dev/en/modules/pwm/
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>


const char* ssid = "WhyFy"; // wifi lan Station ID netwerk naam [School: Medialab | Thuis: NETGEAR_2GEXT]
const char* password = "harry345^"; // wifi lan wachtwoord [School: Mediacollege | Thuis: DB67437ac17871]
const char*  server = "gamereach.nl"; // deployment server

String path = "/control.json"; // path to file

static const uint8_t wifiConnecting = D1;//LED indicator wifi status flashing while connecting
static const uint8_t wifiOk = D2;//LED indicator wifi status ON if connected
static const uint8_t Led1 = D3;//LED indicator wifi status ON if connected


boolean debug = true;// print debug messages to terminal
String httpResponse;// response from webserver


void setup()
{
	Serial.begin(115200);// start serial monitor
	pinMode(wifiConnecting, OUTPUT);//LED indicator wifi status flashing while connecting
	pinMode(wifiOk, OUTPUT);//LED indicator wifi status ON if connected
	pinMode(Led1, OUTPUT);
	digitalWrite(wifiConnecting, LOW);//init off
	digitalWrite(wifiOk, LOW);//init off
	delay(10);
}

void loop()
{
	if (WiFi.status() != WL_CONNECTED)
		wifiConnect();

	httpRequest();//get data from webserver
	if (debug)
		Serial.println(httpResponse);

	payload();//extract wanted data from HTTP response
	if (debug)
		Serial.println(httpResponse); //debug

	extractJson();


}



void extractJson()
{
	//extract JSON string from HTTP data
	int size = httpResponse.length() + 1;
	char json[size];
	httpResponse.toCharArray(json, size);

	StaticJsonDocument<256> json_object; //<==== nieuwe lib

	DeserializationError error = deserializeJson(json_object, json); // <==== nieuwe lib

	if (error)
	{
		Serial.print(F("derserializeJson() failed: "));
		Serial.println(error.c_str());
		return;
	}

	parseJson(json_object);//parse the commands from the json object


}

void parseJson(JsonDocument & json_object)
{
	//parse the commands from the json object
	if (json_object["Led1"] == "on") // ==0 is equal
	{
		Serial.print("device 1 on value => ");
		digitalWrite(Led1, HIGH);
	}
	else
	{
		digitalWrite(Led1, LOW);
	}
}

void payload()
{
	// extract wanted data from HTTP response
	String endOfHeader = "\r\n\r\n";
	int foundEOH = -1;
	// look for EOH end of header
	for (int i = 0; i <= httpResponse.length() - endOfHeader.length(); i++)
	{
		if (httpResponse.substring(i, endOfHeader.length() + i) == endOfHeader)
		{
			foundEOH = i;
		}
	}
	httpResponse = httpResponse.substring(foundEOH);// strip the HTTP header
}

void httpRequest()
{
	// get HTTP response from webserver
	digitalWrite(wifiOk, LOW);//flash LED
	delay(2000);//time between requests
	digitalWrite(wifiOk, HIGH);//flash LED
	httpResponse = ""; //empty string
	WiFiClient client; //instance

	if (client.connect(server, 80))
	{ //connect to webserver on port 80
		client.println("GET " + path + " HTTP/1.1");//construct a HTTP GET request
		client.println("Host: " + String(server));
		client.println("Connection: keep-alive");
		client.println();
	}
	else
	{
		Serial.println("Webserver does not respond");
		return;
	}

	while (client.connected())
	{
		while (client.available())
		{
			httpResponse += char(client.read());//mogelijk memory problemen
			if (httpResponse.length() > 450)
			{
				Serial.println("Receive buffer overflow");//prevent buffer overflow
				httpResponse = ""; //empty string
				return;
			}
		}
	}
}

void wifiConnect()
{
	// connect to local network
	int ledState = 0;//flasher
	digitalWrite(wifiOk, LOW);
	digitalWrite(wifiConnecting, HIGH);
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);
	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
		if (ledState == 0) ledState = 1;
		else ledState = 0;
		digitalWrite(wifiConnecting, ledState);
	}

	Serial.println("");
	Serial.print("WiFi connected, IP address: " + WiFi.localIP());
	if (debug) WiFi.printDiag(Serial); // print Wi-Fi diagnostic information
	digitalWrite(wifiConnecting, LOW);
	digitalWrite(wifiOk, HIGH);
}