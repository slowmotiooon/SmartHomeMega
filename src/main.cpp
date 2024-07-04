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

float temperature = 0;
float humidity = 0;
bool fanState = false;
bool doorState = false;
bool windowState = true;
int lightness = 1023;
int settledLightness = 0;
bool fireState = false;
bool smokeState = false;
String rfidContent = "";

//defineTask(video)
//
//void video::setup() {
//    Serial.begin(500000);
//    Serial3.begin(500000);
//}
//
//
//void video::loop(){
//    while(Serial3.available()) {
//        Serial.write(Serial3.read());
//    }
//}

void setup() {
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
    mySCoop.start();
// write your initialization code here
}

void loop() {
    hazardDetect();
    yield();
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
// write your code here
}