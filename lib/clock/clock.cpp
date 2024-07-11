#include <clock.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include <pins.h>

ThreeWire clockWire(CLOCK_DAT,CLOCK_CLK,CLOCK_RST);
RtcDS1302<ThreeWire> clock(clockWire);

void clockInit(){

    clock.Begin();

    if(clock.GetIsWriteProtected()){
        Serial.println("RTC write protected.");
        clock.SetIsWriteProtected(false);
    }
    if(!clock.GetIsRunning()){
        Serial.println("RTC not run");
        clock.SetIsRunning(true);
    }

//    RtcDateTime now = clock.GetDateTime();
//    if(now<compiled){
//        Serial.println("Updating time");
//        clock.SetDateTime(compiled);
//    }
}

String getDateTime(){
    RtcDateTime now = clock.GetDateTime();
    //Serial.println(String(int(now.Year())));
    String time = String(int(now.Hour())) + ":" + String((int)now.Minute())/*+":"+String((int)now.Second())*/;
    String date = String((int)now.Year())+"/"+String((int)now.Month())+"/"+String((int)now.Day())+ " " + now.DayOfWeek();
    //Serial.println(date);
    //Serial.println(time);
    return date + " " + time;
}

