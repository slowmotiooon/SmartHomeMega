#include <infrared.h>
#include <Arduino.h>
#include <light.h>

void infraredInit(){
    pinMode(INFRARED_PIN,INPUT);
}

void existsPerson(){
    if(digitalRead(INFRARED_PIN)==HIGH) quitLightForce();
    else setLightness(0,true);
}