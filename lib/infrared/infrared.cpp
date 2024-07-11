#include <infrared.h>
#include <Arduino.h>
#include <light.h>
#include <pins.h>

extern int settledLightness;

void infraredInit(){
    pinMode(INFRARED_PIN,INPUT);
}

void existsPerson(){
//    Serial1.println(digitalRead(INFRARED_PIN));
//    if(digitalRead(INFRARED_PIN)==LOW) setLightness(0,true);
//    else if(settledLightness==0) quitLightForce();
}