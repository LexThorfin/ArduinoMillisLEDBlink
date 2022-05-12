unsigned long pMillis = 0;
const int ledPin = LED_BUILTIN;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long cMillis = millis();
  int rnd = cMillis % 1000;

  if(pMillis == cMillis) {
    return;
  }
  
  if (rnd == 0)
  {
    Serial.println("Change LED State");
    ChangePinState(cMillis);
  }
}

void ChangePinState(unsigned long cMil){
  if (ledState == LOW)
  {
    pMillis = cMil;
    ledState = HIGH;
    digitalWrite(ledPin, ledState);
  } else {
    pMillis = cMil;
    ledState = LOW;
    digitalWrite(ledPin, ledState);
  }  
}
