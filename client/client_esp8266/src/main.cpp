#include <Arduino.h>
#include <ESP8266WiFi.h>

void doseQuarterLiter();
void floatSwitchISR();

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
// Accessed by the ISR, used by main loop()
volatile boolean switchFlag = false;

void setup() {
  Serial.begin(9600);
  pinMode(floatSwitchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(floatSwitchPin), floatSwitchISR, FALLING);
  pinMode(relayPin, OUTPUT);
}

// Digital pin cannot supply enough current to power the peristaltic pump's dc motor
// Need a relay, split into a power supply, connected to the peristaltic pump
void loop() {
  if (switchFlag) {
    Serial.println("DOSING");
    delay(2000);
    switchFlag = false;
  } else {
    Serial.println("Not Dosing");
    delay(2000);
    switchFlag = false;
  }
}

void IRAM_ATTR floatSwitchISR() {
  if (digitalRead(floatSwitchPin) == 0) {
    switchFlag = true;
  } else {
    switchFlag = false;
  }
}

void doseQuarterLiter() {
  digitalWrite(relayPin, HIGH);
  // 1/4L at 5v
  delay(610000);
}