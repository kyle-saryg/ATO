#include <Arduino.h>

const int floatSwitch = 2;

void setup() {
  Serial.begin(9600);

  pinMode(floatSwitch, INPUT_PULLUP);
}

// Digital pin cannot supply enough current to power the peristaltic pump's dc motor
// Need a relay, split into a power supply, connected to the peristaltic pump
void loop() {
  int switchFlag = digitalRead(floatSwitch);
  Serial.println(switchFlag);

  if(switchFlag) {
    digitalWrite(4, HIGH);
  }
  delay(500);
}