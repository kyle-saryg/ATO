#include <Arduino.h>

const int floatSwitch = 2;

void setup() {
  Serial.begin(9600);

  pinMode(floatSwitch, INPUT_PULLUP);
}

void loop() {
  int switchFlag = digitalRead(floatSwitch);
  Serial.println(switchFlag);

  if(switchFlag) {
    Serial.println("Inside if");
    digitalWrite(4, HIGH);
  }
  delay(500);
}

// put function definitions here