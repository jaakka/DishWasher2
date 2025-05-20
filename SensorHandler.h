#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include <Arduino.h>

enum BoolSensor : byte
{
    Door,
    Leak,
    Level,
    Overheat
};

enum FloatSensor : byte
{
    Temp,
    Qual
};

bool readSensorState(BoolSensor sensor);
float readSensorState(FloatSensor sensor);