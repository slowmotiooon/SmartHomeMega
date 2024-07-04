#include <window.h>
#include <oled.h>

Servo windowServo;
extern bool windowState;
bool forcedWindow = false;

void windowInit(){
    windowServo.attach(WINDOW_PIN);
    windowServo.write(OPEN_ANGLE);
}

void windowOpen(bool force){
    if(forcedWindow && !force) return;
    if(windowState) return;
    windowServo.write(OPEN_ANGLE);
    delay(1000);
    windowState = true;
    updateInfo();
    forcedWindow = force;
}

void windowClose(bool force){
    if(forcedWindow && !force) return;
    if(!windowState) return;
    windowServo.write(CLOSE_ANGLE);
    delay(1000);
    windowState = false;
    updateInfo();
    forcedWindow = force;
}

void quitWindowForce(){
    forcedWindow = false;
}
