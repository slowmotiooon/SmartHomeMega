#ifndef SMARTHOME_DOOR_H
#define SMARTHOME_DOOR_H

#include <Servo.h>
#include <Arduino.h>

#define DOOR_PIN 3
#define OPEN_ANGLE 90
#define CLOSE_ANGLE 180

void doorInit();
void doorOpen();
void doorClose(bool isWelcome = true);

#endif //SMARTHOME_DOOR_H
