#ifndef RELAYHANDLER_H
#define RELAYHANDLER_H

#include <Arduino.h>

enum Relay : byte
{
    RELAY_1,
    RELAY_2,
};

void setRelayState(Relay relay, bool newState);
bool getState(Relay relay);

#endif