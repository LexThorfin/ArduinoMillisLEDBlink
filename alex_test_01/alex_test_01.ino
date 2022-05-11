unsigned long pMillis = 0;
unsigned long prevMillis = 0;
const int ledPin = LED_BUILTIN;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long cMillis = millis();
  
  int rnd = cMillis % 500;

  if(prevMillis == cMillis) {
    return;
  }
  
  if (rnd == 0)
  {
    ChangePinState(cMillis);
  }
}

void ChangePinState(unsigned long cMil){
  if (ledState == LOW)
  {
    prevMillis = cMil;
    ledState = HIGH;
    digitalWrite(ledPin, ledState);
  } else {
    prevMillis = cMil;
    ledState = LOW;
    digitalWrite(ledPin, ledState);
  }  
}
