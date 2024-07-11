#include <remote.h>
#include <IRremote.h>
#include <pins.h>

IRrecv irrecv(RECV_PIN);
decode_results results;

void remoteInit(){
    irrecv.enableIRIn();
}

void detectRecv(){
    if(irrecv.decode(&results)){
        //Serial.println(results.value,HEX);
        irrecv.resume();
    }
}

