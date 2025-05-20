#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include <Arduino.h>

bool readSensorState(byte bool_sensor);
byte readSensorState(byte float_sensor);

#endif