#include <dht_fan.h>

extern float humidity;
extern float temperature;
extern bool fanState;
DHT dht(DHTPIN,DHTTYPE);
bool forcedFan = false;

// 初始化 DHT 传感器和风扇控制引脚
void dhtInit() {
    Serial.begin(9600); // 启动串行通信
    dht.begin(); // 初始化 DHT 传感器
    pinMode(FAN_IA, OUTPUT); // 设置风扇控制引脚为输出模式
    pinMode(FAN_IB, OUTPUT);
    fanClose(); // 初始状态下关闭风扇
}

// 读取温湿度数据
void readDHT() {
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();

    dhtJudge();
}

// 到没到28度
void dhtJudge() {
    if(temperature>30 && !fanState){
        if(!forcedFan) fanOpen();
    }
    if(temperature<=30 && fanState){
        if(!forcedFan) fanClose();
    }
}

// 开启风扇
void fanOpen(bool force) {
    digitalWrite(FAN_IA, HIGH);
    //digitalWrite(FAN_IB,HIGH);// 设置电机正转
    fanState = true;
    forcedFan = force;
}

// 关闭风扇
void fanClose(bool force) {
    digitalWrite(FAN_IA, LOW); // 停止电机
    //digitalWrite(FAN_IB,LOW);
    fanState = false;
    forcedFan= force;
}

void quitFanForce(){
    forcedFan = false;
}

