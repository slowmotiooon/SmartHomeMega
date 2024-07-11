#include <Arduino.h>
#include <oled.h>
#include "dht_fan.h"
#include "door.h"
#include <rfid.h>
#include <touch.h>
#include <rain.h>
#include <light.h>
#include <remote.h>
#include <bluetooth.h>
#include <hazard.h>
#include <vocal.h>
#include <infrared.h>
#include <SCoop.h>
#include <clock.h>

float temperature = 0;
float humidity = 0;
bool fanState = false;
bool doorState = false;
bool windowState = true;
int lightness = 1023;
int settledLightness = 0;
bool fireState = false;
bool smokeState = false;
bool enableAutoRefresh = true;
String rfidContent = "";

defineTask(clockTask)

void clockTask::setup() {
}


void clockTask::loop(){
    //updateInfo();
    delay(500);
}

void setup() {
    Serial.begin(9600);
    btInit();
    oledInit();
    dhtInit();
    doorInit();
    rfidInit();
    touchInit();
    rainInit();
    remoteInit();
    hazardInit();
    vocalInit();
    infraredInit();
    clockInit();
    mySCoop.start();
// write your initialization code here
}

void loop() {
    hazardDetect();
    //yield();
    readDHT();
    rfidCheck();
    existsPerson();
    setLightState();
    judgeTouch();
    judgeRain();
    detectRecv();
    getMessage();
    vocalDetect();
    updateInfo();
    //getDateTime();
// write your code here
}