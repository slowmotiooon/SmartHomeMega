#include "hazard.h"
#include <Arduino.h>
#include <beep.h>
#include <pins.h>

extern bool smokeState;
extern bool fireState;

void hazardInit(){
    pinMode(FIRE_PIN,INPUT);
    pinMode(SMOKE_PIN,INPUT);
}

void hazardDetect(){
    smokeState = !digitalRead(SMOKE_PIN);
    fireState = !digitalRead(FIRE_PIN);
    //Serial.print(smokeState);
    //Serial.print("\t");
    //Serial.println(fireState);
    if(smokeState || fireState) alarm();
}