#include <Arduino.h>
#include<stdlib.h>


int counterVal = 0;
boolean buttonState;
#define BTN 7

boolean debounceButton(boolean state) {
  boolean stateNow = digitalRead(BTN);
  if (state != stateNow) {
    delay(10);
    stateNow = digitalRead(BTN);
  }
  return stateNow;
}

void setup() {
  Serial.begin(9600);
  pinMode(BTN, INPUT);
  Serial.println("====Start Program====");

}

void loop() {

  if (debounceButton(BTN) == HIGH && buttonState == LOW) {
    counterVal = counterVal + 1;
    Serial.print("COUNTER: ");
    Serial.println(counterVal);
    buttonState = HIGH;
  }
  else if (debounceButton(BTN) == LOW && buttonState == HIGH) {
    buttonState = LOW;
  }
}