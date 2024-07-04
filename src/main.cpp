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

void setup() {
    Serial.begin(9600);
    oledInit();
    dhtInit();
    doorInit();
    rfidInit();
    touchInit();
    rainInit();
    remoteInit();
    btInit();
    hazardInit();
    vocalInit();
    infraredInit();

// write your initialization code here
}

void loop() {
    hazardDetect();
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
    delay(10);
// write your code here
}