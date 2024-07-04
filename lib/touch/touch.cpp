#include <touch.h>
#include <beep.h>

void touchInit(){
    pinMode(TOUCH_PIN,INPUT);
    beepInit();
}

void judgeTouch(){
    //Serial.println(digitalRead(TOUCH_PIN));
    if(digitalRead(TOUCH_PIN)==HIGH){
        doorbell();
    }
}
