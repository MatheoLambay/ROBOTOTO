#ifndef FACE_FONCTION_H
#define FACE_FONCTION_H

#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display; //123 58

void init_oled();
void sleep_face_frames(int frame);
void draw_sleep_face();
void draw_normal_face();
void normal_face_frames(int frame);

#endif