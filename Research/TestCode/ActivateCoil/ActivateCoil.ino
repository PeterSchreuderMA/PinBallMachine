int buttonPin0 = A0;// Push button input
int buttonPin1 = A1;// Push button input
int coilPin0 = 7;
int coilPin1 = 8;

int targetPin0 = 10;

void setup() 
{
  Serial.begin(9600);

  //- Buttons
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);

  //- Flippers
  pinMode(coilPin0, OUTPUT);
  pinMode(coilPin1, OUTPUT);

  //- Targets
  pinMode(targetPin0, INPUT);
}

void loop() 
{
  
  ActivateCoil(buttonPin0, coilPin0);
  ActivateCoil(buttonPin1, coilPin1);

  if (CheckTarget(10))
    Serial.println("Target Hit!");
}


void ActivateCoil(int _button, int _coil)
{
  //digitalWrite(pushB, HIGH);
  
  if (digitalRead(_button) == HIGH)
  {
    //Serial.println("Pressed" + String(_coil));
    
    //delay(300);
    digitalWrite(_coil, HIGH);
    //delay(300);
  }
  else
  {
    digitalWrite(_coil, LOW);
  }
}


bool CheckTarget(int _index)
{
  bool _return = false;

  if (digitalRead(_index) == HIGH)
    _return = true;
  
  return _return;
  
}
