#include "wifi.h"
#include <Arduino.h>

void wifiInit(){
    Serial3.begin(9600);
}

String getMessage(){
    String message;
    while(Serial3.available()>0){
        message.concat(Serial3.read());
    }
    if(message.startsWith("2")) return message;
    else return "\0";
}

String getWebDateTime(){
    Serial3.print("_getDateTime");
    String result;
    do{
        result = getMessage();
    } while(result.equals("\0"));

    return result;
}