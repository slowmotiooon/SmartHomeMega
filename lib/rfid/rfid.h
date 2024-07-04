//
// Created by dynan on 2024/7/2.
//

#ifndef SMARTHOME_RFID_H
#define SMARTHOME_RFID_H


#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 49

void rfidInit();
void rfidCheck();

#endif //SMARTHOME_RFID_H
