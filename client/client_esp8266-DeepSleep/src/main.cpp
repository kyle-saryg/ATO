#include <Arduino.h>

void doseQuarterLiter();

/*
  WeMos D1:
    -- GPIO2 (Programmatical Reference) -> D4 (Physical Pinout)
    -- GPIO4 (Programmatical Reference) -> D2 (Physical Pinout)
*/

// Wire float switch to pin 2
// Connect other end to GND
const int floatSwitchPin = 2;
// Relay input on pin 4
const int relayPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(floatSwitchPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
}

// Digital pin cannot supply enough current to power the peristaltic pump's dc motor
// Need a relay, split into a power supply, connected to the peristaltic pump
void loop() {
  // Read water level
  int switchFlag = digitalRead(floatSwitchPin);

  if(switchFlag == 0) {
    Serial.println(switchFlag);
    doseQuarterLiter();
  } else {
    digitalWrite(relayPin, LOW);
    Serial.println(switchFlag);
  }
  delay(500);
}

void doseQuarterLiter() {
  digitalWrite(relayPin, HIGH);
  // 1/4L at 5v
  delay(610000);
}