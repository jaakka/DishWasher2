#ifndef LCDHANDLER_H
#define LCDHANDLER_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Pins.h"

enum Line : byte
{
    Line1,
    Line2,
};

void drawText(Line line, const char *msg);
void initLcd();
void sendLcdCommand(const char *cmd);

#endif