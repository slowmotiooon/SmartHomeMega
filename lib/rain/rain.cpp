#include <rain.h>
#include <Arduino.h>
#include <window.h>
#include <pins.h>

extern bool windowState;

void rainInit(){
    pinMode(RAIN_PIN,INPUT);
    windowInit();
}

void judgeRain(){
    if(digitalRead(RAIN_PIN)==LOW && windowState) windowClose();
    else if(digitalRead(RAIN_PIN)==HIGH && !windowState) windowOpen();
}

