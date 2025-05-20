#ifndef LCDHANDLER_H
#define LCDHANDLER_H

#include <Arduino.h>

enum Line : byte
{
    Line1,
    Line2,
};

void drawText(Line line, const char* msg);

#endif