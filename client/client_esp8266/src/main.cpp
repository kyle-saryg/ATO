#include <Arduino.h>

/*
Default: 1 (because of the internal pull-up resistor)

Want: Relay to be disconnected
  IF: Float switch is disconnected
    TRUE when disconnected

Relay: Normally Open
  Disconnected Float (True): CLOSED
*/


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
    digitalWrite(relayPin, HIGH);
    Serial.println(switchFlag);
    // 1/4th of a cup
    delay(450000);
  } else {
    digitalWrite(relayPin, LOW);
    Serial.println(switchFlag);
  }
  delay(500);
}