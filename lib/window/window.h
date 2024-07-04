#ifndef SMARTHOMEMEGA_WINDOW_H
#define SMARTHOMEMEGA_WINDOW_H

#include <Servo.h>
#include <Arduino.h>

#define WINDOW_PIN 4
#define OPEN_ANGLE 180
#define CLOSE_ANGLE 90

void windowInit();
void windowOpen(bool force = false);
void windowClose(bool force = false);
void quitWindowForce();

#endif //SMARTHOMEMEGA_WINDOW_H
