#pragma once

#include <Servo.h>
#include <Arduino.h>

#define OPEN_ANGLE 180
#define CLOSE_ANGLE 90

void windowInit();
void windowOpen(bool force = false);
void windowClose(bool force = false);
void quitWindowForce();

