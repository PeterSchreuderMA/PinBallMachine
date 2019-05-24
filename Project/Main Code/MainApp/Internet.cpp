// 
// 
// 

#include "Internet.h"


#include <SoftwareSerial.h>

#define DEBUG true

SoftwareSerial esp8266(2, 3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
							 // This means that you need to connect the TX line from the esp to the Arduino's pin 2
							 // and the RX line from the esp to the Arduino's pin 3

void InternetClass::InternetSetup()
{
	Serial.begin(9600);
	esp8266.begin(9600); // your esp's baud rate might be different

	

	InternetSendData("AT+RST\r\n", 2000, DEBUG); // reset module
	InternetSendData("AT+CWMODE=2\r\n", 1000, DEBUG); // configure as access point
	InternetSendData("AT+CIFSR\r\n", 1000, DEBUG); // get ip address
	InternetSendData("AT+CIPMUX=1\r\n", 1000, DEBUG); // configure for multiple connections
	InternetSendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG); // turn on server on port 80
}

void InternetClass::InternetCheckSend()
{
	if (esp8266.available()) // check if the esp is sending a message 
	{

		if (esp8266.find("+IPD,"))
		{
			delay(1000);

			int connectionId = esp8266.read() - 48; // subtract 48 because the read() function returns 
												  // the ASCII decimal value and 0 (the first decimal number) starts at 48

			String webpage = "<h1>Hello</h1>&lth2>World!</h2><button>LED1</button>";

			String cipSend = "AT+CIPSEND=";
			cipSend += connectionId;
			cipSend += ",";
			cipSend += webpage.length();
			cipSend += "\r\n";

			InternetSendData(cipSend, 1000, DEBUG);
			InternetSendData(webpage, 1000, DEBUG);

			webpage = "<button>LED2</button>";

			cipSend = "AT+CIPSEND=";
			cipSend += connectionId;
			cipSend += ",";
			cipSend += webpage.length();
			cipSend += "\r\n";

			InternetSendData(cipSend, 1000, DEBUG);
			InternetSendData(webpage, 1000, DEBUG);

			String closeCommand = "AT+CIPCLOSE=";
			closeCommand += connectionId; // append connection id
			closeCommand += "\r\n";

			InternetSendData(closeCommand, 3000, DEBUG);
		}
	}
}

String InternetClass::InternetSendData(String _command, const int _timeout, boolean _debug)
{
	String _response = "";

	esp8266.print(_command); // send the read character to the esp8266

	long int _time = millis();

	while ((_time + _timeout) > millis())
	{
		while (esp8266.available())
		{

			// The esp has data so display its output to the serial window 
			char _c = esp8266.read(); // read the next character.
			_response += _c;
		}
	}

	if (_debug)
	{
		Serial.print(_response);
	}

	return _response;
}


InternetClass Internet;

