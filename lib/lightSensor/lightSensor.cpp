#include <lightSensor.h>
#include <Arduino.h>
#include <pins.h>

extern int lightness;

void lightSensorInit(){

}

void detectLightness(){
    lightness = analogRead(LIGHT_SENSOR_PIN);
}