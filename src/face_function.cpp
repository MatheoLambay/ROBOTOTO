#include <iostream>
#include "face_function.h"

Adafruit_SSD1306 display(128,64, &Wire, -1);

const unsigned long frameInterval_face = 500; // 500 ms

unsigned long previousMillis_face_sleep = 0;
int currentFrame_face_sleep = 0;
const int totalFrames_face_sleep = 4;


unsigned long previousMillis_face_normal = 0;
int currentFrame_face_normal = 0;
const int totalFrames_face_normal = 2;

int normal_face_animation = 0;


void init_oled(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
    delay(200);
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.display();
}

void draw_sleep_face(){

    unsigned long currentMillis_face_sleep = millis();
    if (currentMillis_face_sleep - previousMillis_face_sleep >= frameInterval_face){
        previousMillis_face_sleep = currentMillis_face_sleep;
        sleep_face_frames(currentFrame_face_sleep);
        currentFrame_face_sleep = (currentFrame_face_sleep + 1) % totalFrames_face_sleep; 
        currentFrame_face_normal = 0;
    }
}


void draw_normal_face(){

    unsigned long currentMillis_face_normal = millis();
    if (currentMillis_face_normal - previousMillis_face_normal >= frameInterval_face){
        previousMillis_face_normal = currentMillis_face_normal;
        normal_face_frames(currentFrame_face_normal);
        currentFrame_face_normal = (currentFrame_face_normal + 1) % totalFrames_face_normal; 
        currentFrame_face_sleep = 0;
    }
}

void sleep_face_frames(int frame){
    
    switch (frame) {
        case 0:
            display.setCursor(0,0);
            display.setTextSize(1);
            display.clearDisplay();
            display.drawCircle(61, 51, 8, SSD1306_WHITE);
            display.drawLine(24, 32, 40, 32, SSD1306_WHITE);
            display.drawLine(75, 32, 94, 32, SSD1306_WHITE);
            display.drawLine(23, 31, 19, 28, SSD1306_WHITE);
            display.drawLine(40, 32, 46, 29, SSD1306_WHITE);
            display.drawLine(94, 32, 101, 29, SSD1306_WHITE);
            display.drawLine(74, 32, 68, 29, SSD1306_WHITE);
            break;
        case 1:
            display.setTextSize(2);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(68, 11);
            display.print(F("Z"));
            break;
        case 2:
            display.setCursor(87, 10);
            display.print(F("Z"));
            break;
        case 3:
            display.setCursor(104, 8);
            display.print(F("Z"));
            break;
    }
    display.display();
}

void normal_face_frames(int frame){

    if(normal_face_animation == 0){
        switch (frame) {
            
            case 0:
                display.clearDisplay();
                display.setTextSize(5);
                display.setTextColor(SSD1306_WHITE);
                display.setCursor(30, 18);
                display.print(F("^"));
                
                display.setTextSize(5);
                display.setTextColor(SSD1306_WHITE);
                display.setCursor(74, 18);
                display.print(F("^"));
                
                display.drawLine(47, 54, 80, 54, SSD1306_WHITE);
                display.drawLine(81, 53, 91, 51, SSD1306_WHITE);
                break;
            case 1:
                display.clearDisplay();
                display.setTextSize(5);
                display.setTextColor(SSD1306_WHITE);
                display.setCursor(30, 15);
                display.print(F("^"));
                
                display.setTextSize(5);
                display.setTextColor(SSD1306_WHITE);
                display.setCursor(74, 15);
                display.print(F("^"));
                
                display.drawLine(47, 54, 80, 54, SSD1306_WHITE);

                display.drawLine(81, 53, 91, 51, SSD1306_WHITE);
                break;

        }
    }
    display.display();


}

