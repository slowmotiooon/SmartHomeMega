#include <vocal.h>
#include <Arduino.h>
#include <dht_fan.h>
#include <light.h>
#include <window.h>

void vocalInit(){
    Serial2.begin(19200);
    Serial.print("vocal ok");
}

void vocalDetect(){
    String command;
    if(Serial2.available()>0){
        Serial.print("available");
        command.concat((char)Serial2.read());
    }

    if(!command.length()) return;

    if(command == "0"){                             //智能开灯语音
        Serial.println("Detected voice command: Turn on the light");
        setLightness(255, true);
    }
    if(command == "1"){                             //智能关灯语音
        Serial.println("Detected voice command: Turn off the light");
        setLightness(0, true);
    }
    if(command == "2"){                             //智能控制灯语音
        Serial.println("Detected voice command: Control the light");
        quitLightForce();
    }
    if(command == "3"){                             //智能开风扇语音
        Serial.println("Detected voice command: Turn on the fan");
        fanOpen(true);
    }
    if(command == "4"){                             //智能关风扇语音
        Serial.println("Detected voice command: Turn off the fan");
        fanClose(true);
    }
    if(command == "5"){                             //智能控制风扇语音
        Serial.println("Detected voice command: Control the fan");
        quitFanForce();
    }
    if(command == "6"){                             //智能开窗语音
        Serial.println("Detected voice command: Open the window");
        windowOpen(true);
    }
    if(command == "7"){                             //智能关窗语音
        Serial.println("Detected voice command: Close the window");
        windowClose(true);
    }
    if(command == "8"){                             //智能控制窗户语音
        Serial.println("Detected voice command: Control the window");
        quitWindowForce();
    }

}
