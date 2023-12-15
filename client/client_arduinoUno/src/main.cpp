#include <Arduino.h>

// Wire float switch to pin 2
// Connect other end to GND
const int floatSwitchPin = 2;
const int relayPin = 4;

void setup() {
  Serial.begin(9600);

  pinMode(floatSwitchPin, INPUT_PULLUP);
}

// Digital pin cannot supply enough current to power the peristaltic pump's dc motor
// Need a relay, split into a power supply, connected to the peristaltic pump
void loop() {
  int switchFlag = digitalRead(floatSwitchPin);
  Serial.println(switchFlag);

  if(switchFlag) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
  delay(500);
}