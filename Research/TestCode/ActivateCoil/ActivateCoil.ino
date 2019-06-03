int pushB = A0;// Push button input
int relayPin = 7;

void setup() 
{
  Serial.begin(9600);

  pinMode(pushB, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() 
{
  
  ActivateCoil();
}


void ActivateCoil()
{
  //digitalWrite(pushB, HIGH);
  
  if (digitalRead(pushB) == HIGH)
  {
    Serial.println("Pressed");
    
    //delay(300);
    digitalWrite(relayPin, HIGH);
    //delay(300);
  }
  else
  {
    digitalWrite(relayPin, LOW);
  }
}
