#include <Arduino.h>
#include <face_function.h>

#define btns_pin 14

const unsigned long frameInterval_sleep = 10000; 
unsigned long previousMillis_sleep = 0;

bool veille = 0;


void setup() {

  Serial.begin(115200);
  init_oled();
  
}

void loop() {

  unsigned long currentMillis_sleep = millis();
  if (currentMillis_sleep - previousMillis_sleep >= frameInterval_sleep) {
    veille = 1;
    Serial.println(1);
  }
  else{
    veille = 0;
    Serial.println(0);
  }

  if(veille == 1){
    draw_sleep_face();
  }
  else{
    draw_normal_face();
  }
    
  
  int potValue = analogRead(btns_pin);
  if(potValue == 0){
    Serial.println("btn");
    previousMillis_sleep = currentMillis_sleep;
  }
  

}

