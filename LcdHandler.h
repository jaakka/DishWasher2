#ifndef LCDHANDLER_H
#define LCDHANDLER_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Pins.h"
#include "Values.h"

void drawText(byte line, const char *msg);
void initLcd();
void sendLcdCommand(const char *cmd);
void clearLcd();
void drawImage(byte elementId, byte imageId);

#endif