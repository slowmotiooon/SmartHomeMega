#include <door.h>
#include "oled.h"
#include <Servo.h>
#include <Arduino.h>
#include <pins.h>

Servo doorServo;
extern bool doorState;

void doorInit(){
    doorServo.attach(DOOR_PIN);
    doorState = false;
    doorServo.write(CLOSE_ANGLE);
    delay(1000);
}

void doorOpen(){
    doorState = true;
    welcome();
    doorServo.write(OPEN_ANGLE);
    delay(1000);

}

void doorClose(bool isWelcome){
    doorState = false;
    if(isWelcome) welcome();
    else updateInfo();
    doorServo.write(CLOSE_ANGLE);
    delay(1000);

}