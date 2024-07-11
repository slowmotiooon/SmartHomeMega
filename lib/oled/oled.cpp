#include <oled.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "clock.h"
#include <pins.h>

U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0,U8X8_PIN_NONE,OLED_SCL,OLED_SDA);
extern float temperature;
extern float humidity;
extern bool fanState;
extern bool doorState;
extern bool windowState;
extern int settledLightness;
extern String rfidContent;

void oledInit(){
    u8g2.begin();
    u8g2.setContrast(255);
}

void updateInfo(){
    String timeInfo = getDateTime();
    String date = timeInfo.substring(0,timeInfo.indexOf(' '));
    String time = timeInfo.substring(timeInfo.lastIndexOf(' ')+1);
    int weekday = timeInfo.substring(timeInfo.indexOf(' ')+1,timeInfo.lastIndexOf(' ')).toInt();


    //Serial.println("update info.");
    u8g2.clearBuffer();
    u8g2.firstPage();
    do{
        u8g2.setDrawColor(1);
        u8g2.setFont(u8g2_font_6x10_tr);
        u8g2.drawStr(0,10,timeInfo.c_str());
        u8g2.drawStr(0,20,String(temperature).c_str());
        u8g2.drawStr(30,20,"'C");
        u8g2.drawStr(48,20,String(humidity).c_str());
        u8g2.drawStr(78,20,"%");
        u8g2.drawStr(0,30,"fan:");
        if(fanState){
            u8g2.drawStr(30,30, "opened.");
        }
        else u8g2.drawStr(30,30, "closed.");
        u8g2.drawStr(0,40,"door:");
        if(doorState){
            u8g2.drawStr(36,40, "opened.");
        }
        else u8g2.drawStr(36,40, "closed.");
        u8g2.drawStr(0,50,"window:");
        if(windowState){
            u8g2.drawStr(48,50, "opened.");
        }
        else u8g2.drawStr(48,50, "closed.");
        u8g2.drawStr(0,60,"light level:");
        u8g2.drawStr(72,60,String(settledLightness).c_str());

    } while(u8g2.nextPage());
}

void welcome(){
    u8g2.clearBuffer();
    u8g2.firstPage();
    do{
        u8g2.setDrawColor(1);
        u8g2.setFont(u8g2_font_10x20_tr);
        u8g2.drawStr(0,30,"Welcome Home!");
        u8g2.setFont(u8g2_font_6x10_tr);
        if(doorState) u8g2.drawStr(25,60,"Door is open.");
        else u8g2.drawStr(19,60,"Door is closed.");

    } while(u8g2.nextPage());
}

