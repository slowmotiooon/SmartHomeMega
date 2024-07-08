#ifndef DESIGNANDBUILDING_DHT_FAN_H
#define DESIGNANDBUILDING_DHT_FAN_H


#include <Arduino.h>
#include <DHT.h>

// 定义引脚和传感器类型
#define DHTPIN 48
#define DHTTYPE DHT11 // 定义传感器类型为 DHT11
#define FAN_IA 46
#define FAN_IB 44

// 创建 DHT 传感器对象

// 函数声明
void dhtInit(); // 初始化 DHT 传感器和风扇控制引脚
void readDHT(); // 读取温湿度数据
void dhtJudge(); // 判断温度是否达到标准
void fanOpen(bool force = false); // 开启风扇
void fanClose(bool force = false); // 关闭风扇
void quitFanForce();
void setTemperature(int val);
#endif //DESIGNANDBUILDING_DHT_FAN_H
