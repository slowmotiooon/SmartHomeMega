#ifndef SMARTHOMEMEGA_LIGHT_H
#define SMARTHOMEMEGA_LIGHT_H

#define LED_B 5
#define LED_R 6
#define LED_G 7

void setLightState();
void setLightness(int val,bool force = false);
void quitLightForce();

#endif //SMARTHOMEMEGA_LIGHT_H
