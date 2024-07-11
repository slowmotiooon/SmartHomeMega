#include <rfid.h>
#include "door.h"
#include <SPI.h>
#include <MFRC522.h>
#include <pins.h>

MFRC522 mfrc522(RFID_SS_PIN, RFID_RST_PIN);
extern String rfidContent;

void rfidInit(){
    SPI.begin();
    mfrc522.PCD_Init();
}

void rfidCheck(){
    if(!mfrc522.PICC_IsNewCardPresent()) {
        //rfidContent = "";
        return;
    }
    if(!mfrc522.PICC_ReadCardSerial()) {
        rfidContent = "";
        return;
    }


    //Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    //Serial.println(mfrc522.PICC_GetTypeName(piccType));

    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
        piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
        piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
        //Serial.println(F("Your tag is not of type MIFARE Classic."));
        return;
    }

    //Serial.print("UID tag:");
    rfidContent = "";
    byte letter;
    for(byte i = 0;i<mfrc522.uid.size;i++){
        //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        //Serial.print(mfrc522.uid.uidByte[i], HEX);
        rfidContent.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        rfidContent.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println(rfidContent);

    if(rfidContent.substring(1)=="a3 81 16 2d"){
        //Serial.println("SUCCESS");
        doorOpen();
        delay(2000);
        doorClose();
    }

}
