//
// Created by dynan on 2024/7/3.
//

#include <beep.h>

void beepInit(){
    pinMode(BEEP_PIN,OUTPUT);
    digitalWrite(BEEP_PIN,HIGH);
}

void doorbell(){
    digitalWrite(BEEP_PIN,LOW);
    delay(200);
    digitalWrite(BEEP_PIN,HIGH);
    delay(200);
    digitalWrite(BEEP_PIN,LOW);
    delay(200);
    digitalWrite(BEEP_PIN,HIGH);
    delay(200);
}

void alarm(){
    digitalWrite(BEEP_PIN,LOW);
    delay(90);
    digitalWrite(BEEP_PIN,HIGH);
    delay(90);
    digitalWrite(BEEP_PIN,LOW);
    delay(90);
    digitalWrite(BEEP_PIN,HIGH);
    delay(90);
    digitalWrite(BEEP_PIN,LOW);
    delay(90);
    digitalWrite(BEEP_PIN,HIGH);
    delay(90);
    digitalWrite(BEEP_PIN,LOW);
    delay(90);
    digitalWrite(BEEP_PIN,HIGH);
    delay(90);
}