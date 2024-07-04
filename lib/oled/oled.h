#ifndef SMARTHOME_OLED_H
#define SMARTHOME_OLED_H

#include <Arduino.h>

#define OLED_SCL PIN_A5 //TODO
#define OLED_SDA PIN_A4 //TODO

void oledInit();
void updateInfo();
void welcome();


#endif //SMARTHOME_OLED_H
