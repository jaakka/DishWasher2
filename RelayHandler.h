#ifndef RELAYHANDLER_H
#define RELAYHANDLER_H

#include <Arduino.h>

void setRelayState(byte relay, bool newState);
bool getState(byte relay);

#endif