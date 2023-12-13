#include <Arduino.h>

const int floatSwitch = 2;

void setup() {
  Serial.begin(9600);

  pinMode(floatSwitch, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(floatSwitch));
  delay(500);
}

// put function definitions here