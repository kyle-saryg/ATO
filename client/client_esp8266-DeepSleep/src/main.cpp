#include <Arduino.h>
#include <ESP8266WiFi.h>

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

/*
Sleep Duration calculations:
ESP.deepSleep() takes in an integer representing the number of SECONDS to sleep
*/
const int sleepDurationInHours = 6;
const int sleepDurationInSeconds = sleepDurationInHours * 60 * 60;



void setup() {
  Serial.begin(9600);
  pinMode(floatSwitchPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
}

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
  ESP.deepSleep((sleepDurationInSeconds) * 1e6);
}

void doseQuarterLiter() {
  digitalWrite(relayPin, HIGH);
  // 1/4L at 5v
  delay(610000);
}