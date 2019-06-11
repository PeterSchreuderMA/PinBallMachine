int buttonPin0 = A0;// Push button input
int buttonPin1 = A1;// Push button input
int coilPin0 = 7;
int coilPin1 = 8;

void setup() 
{
  Serial.begin(9600);

  //- Buttons
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);

  //- Flippers
  pinMode(coilPin0, OUTPUT);
  pinMode(coilPin1, OUTPUT);
}

void loop() 
{
  
  ActivateCoil(buttonPin0, coilPin0);
  ActivateCoil(buttonPin1, coilPin1);
}


void ActivateCoil(int _button, int _coil)
{
  //digitalWrite(pushB, HIGH);
  
  if (digitalRead(_button) == HIGH)
  {
    Serial.println("Pressed" + String(_coil));
    
    //delay(300);
    digitalWrite(_coil, HIGH);
    //delay(300);
  }
  else
  {
    digitalWrite(_coil, LOW);
  }
}
