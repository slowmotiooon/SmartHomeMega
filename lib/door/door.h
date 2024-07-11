#ifndef SMARTHOME_DOOR_H
#define SMARTHOME_DOOR_H

#define OPEN_ANGLE 90
#define CLOSE_ANGLE 180

void doorInit();
void doorOpen();
void doorClose(bool isWelcome = true);

#endif //SMARTHOME_DOOR_H
