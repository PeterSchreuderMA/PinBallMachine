// 
// 
// 

#include "Internet.h"
#include "PinRemap.h"


/*int wifiConnecting = 0;
int wifiOk = 0;
int Led1 = 0;*/
 
//static const uint8_t wifiConnecting = D1;//LED indicator wifi status flashing while connecting
//static const uint8_t wifiOk = D2;//LED indicator wifi status ON if connected
//static const uint8_t Led1 = D3;//LED indicator wifi status ON if connected

char* ssid; // wifi lan Station ID netwerk naam [School: Medialab | Thuis: NETGEAR_2GEXT | Tel: WhyFy]
char* password; // wifi lan wachtwoord [School: Mediacollege | Thuis: DB67437ac17871 | Tel: harry345^]
char* server; // deployment server

int requestInterval = 10;
int requestAmount = 0;

int sendAmount = 0;

String httpResponse;// response from webserver

WiFiClient client; //instance

void InternetClass::InitInternet(char* _ssid, char* _pw, char* _server, String _docPassword)
{
	debug = true;

	//Fill the variables
	ssid = _ssid;
	password = _pw;
	server = _server;
	docPassword = _docPassword;

	//pinMode(wifiConnecting, OUTPUT);//LED indicator wifi status flashing while connecting
	//pinMode(wifiOk, OUTPUT);//LED indicator wifi status ON if connected
	//pinMode(Led1, OUTPUT);

	//digitalWrite(wifiConnecting, LOW);//init off
	//digitalWrite(wifiOk, LOW);//init off
}

void InternetClass::CheckConnection()
{
	if (WiFi.status() != WL_CONNECTED)
		WifiConnect();
}

void InternetClass::WifiConnect()
{
	// connect to local network
	int ledState = 0;//flasher

	//digitalWrite(wifiOk, LOW);
	//digitalWrite(wifiConnecting, HIGH);

	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);//<========== delay
		Serial.print(".");
		if (ledState == 0) ledState = 1;
		else ledState = 0;
		//digitalWrite(wifiConnecting, ledState);
	}

	Serial.println("");
	Serial.print("WiFi connected, IP address: " + WiFi.localIP().toString());

	if (debug)
		WiFi.printDiag(Serial); // print Wi-Fi diagnostic information

	//digitalWrite(wifiConnecting, LOW);
	//digitalWrite(wifiOk, HIGH);
}

void InternetClass::HttpRequest(String _doc)
{
	// get HTTP response from webserver
//	digitalWrite(wifiOk, LOW);//flash LED

	delay(requestInterval);//time between requests

//	digitalWrite(wifiOk, HIGH);//flash LED

	httpResponse = ""; //empty string

	WiFiClient client; //instance

	if (client.connect(server, 80))
	{
		//test
		//doc = doc + "?test=";
		//end test
		requestAmount++;
		Serial.println("");
		Serial.println("Request number: " + String(requestAmount));

		//connect to webserver on port 80
		client.println("GET " + _doc + " HTTP/1.1");//construct a HTTP GET request
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

	if (debug)
	{
		Serial.println("");
		Serial.println("-------Full Request-------");
		Serial.println(httpResponse); //debug
		Serial.println("--------------------------");
		Serial.println("");
	}
}

void InternetClass::HttpSend(String _file, String _data)
{

	if (client.connect(server, 80))
	{
		client.setNoDelay(true);

		sendAmount++;
		Serial.println("");
		Serial.println("Send number: " + String(sendAmount));
		
		// - Make a string with the file path, password to the file and data
		String _dataString = _file + "?passWord=" + docPassword + _data;

		//connect to webserver on port 80
		client.println("GET " + _dataString + " HTTP/1.1");//construct a HTTP GET request
		client.println("Host: " + String(server));
		client.println("Connection: keep-alive");
		client.println();
	}
	else
	{
		Serial.println("Webserver does not respond");
		return;
	}
}



void InternetClass::ParseJson(JsonDocument & _json_doc)
{
	//parse the commands from the json object
	if (_json_doc["Led1"] == "on")
	{
		Serial.println("Led1 is on");
		//digitalWrite(Led1, HIGH);
	}
	else
	{
		Serial.println("Led1 is off");
		//digitalWrite(Led1, LOW);
	}
}

void InternetClass::Payload()
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

	if (debug)
	{
		Serial.println("");
		Serial.println("-------JSON-------");
		Serial.println(httpResponse); //debug
		Serial.println("------------------");
		Serial.println("");
	}
}

void InternetClass::ExtractJson()
{
	//extract JSON string from HTTP data
	int size = httpResponse.length() + 1;
	char json[size];

	httpResponse.toCharArray(json, size);

	StaticJsonDocument<256> json_object;

	DeserializationError error = deserializeJson(json_object, json);

	if (error)
	{
		Serial.print(F("derserializeJson() failed: "));
		Serial.println(error.c_str());
		return;
	}

	ParseJson(json_object);//parse the commands from the json object
}



InternetClass Internet;

