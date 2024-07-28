//#####################################################
// การทำงานของสวิตซ์ กดติด กดดับ
#include <Arduino.h>

const int button = 2;
const int led = 11;

int ledState = LOW;
int buttonState;
int lastButtonState = HIGH;           //ยังไม่กดปุ่ม

unsigned long lastTime = 0;
unsigned long preiod = 50;

void toggle_switch();
//######################################################
void setup() {
  pinMode(button, INPUT);             //ทำงานที่ลอจิก LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, ledState);
}

void loop() {
toggle_switch();
}

//######################################################
void toggle_switch(){
  int reading = digitalRead(button);   //เก็บค่าทีอ่านได้จากสวิตซ์ไปไว้ที่ reading
  if (reading != lastButtonState) {    //ถ้า reading ไม่เท่ากับ lastButtonState
    lastTime = millis();               //ให้นำค่าเวลาจาก millis ไปเก็บไว้ที่่ lastTime  
  }
  if (millis() - lastTime > preiod) { //จะทำงานทูกๆ 50 mS
    if (reading != buttonState) {
      buttonState = reading;          //buttonState = ลอจิก 0
      if (buttonState == LOW) {
        ledState = !ledState;         //
      }
    }
  }
  digitalWrite(led, ledState);        //led ติดสว่าง
  lastButtonState = reading;          //reading = ลอจิก 1
}