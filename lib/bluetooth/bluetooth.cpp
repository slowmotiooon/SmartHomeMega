#include <bluetooth.h>
#include <Arduino.h>
#include <dht_fan.h>
#include <light.h>
#include <window.h>
#include <beep.h>

void btInit(){
    Serial1.begin(9600);
    Serial1.println("bt ok");
}

void getMessage(){
    String command;
    while(Serial1.available()>0){
        //Serial.println("available");
        command.concat((char)Serial1.read());
    }
    if(!command.length()) return;


    if(command.equals("openfan\r\n")) fanOpen(true);
    if(command.equals("closefan\r\n")) fanClose(true);
    if(command.equals("autofan\r\n")) quitFanForce();
    if(command.equals("openlight\r\n")) setLightness(255,true);
    if(command.equals("closelight\r\n")) setLightness(0,true);
    if(command.equals("autolight\r\n")) quitLightForce();
    if(command.equals("openwindow\r\n")) windowOpen(true);
    if(command.equals("closewindow\r\n")) windowClose(true);
    if(command.equals("autowindow\r\n")) quitWindowForce();
    if(command.equals("alarm\r\n")) alarm();
    if(command.startsWith("temperature ")){
        if(command.length()>14){
            Serial1.println(command.substring(12).toInt());
            setTemperature(command.substring(12).toInt());
        }
    }

}