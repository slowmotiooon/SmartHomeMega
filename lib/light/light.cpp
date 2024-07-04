#include <light.h>
#include <lightSensor.h>
#include <Arduino.h>

extern int lightness;
extern int settledLightness;
static bool forcedLight = false;

void setLightState(){
    if(forcedLight) return;
    detectLightness();

    //Serial.println(lightness);
    //int calculatedLightness = (lightness-300)*256/600;
    //Serial.print("cal:");
    //Serial.println(calculatedLightness);
    if(lightness>=896) setLightness(111);
    else if(lightness>=832) setLightness(95);
    else if(lightness>=768) setLightness(79);
    else if(lightness>=704) setLightness(63);
    else if(lightness>=640) setLightness(47);
    else if(lightness>=576) setLightness(31);
    else if(lightness>=512) setLightness(15);
    else if(lightness<512) setLightness(0);
    else return;

}

void setLightness(int val,bool force){
    if(forcedLight && !force) return;
    //Serial1.println("setlightness");
    settledLightness = (val+1)/16;
    analogWrite(LED_B,val);
    analogWrite(LED_G,val);
    analogWrite(LED_R,val);
    forcedLight = force;
}

void quitLightForce(){
    forcedLight = false;
}
