#include "SensorHandler.h"
#include "RelayHandler.h"
#include "LcdHandler.h"

int test = 0;

void setup()
{
    Serial.begin(115200);
    initLcd();
}

void loop()
{
    delay(1000);
    test++;
    char cmd[20];
    snprintf(cmd, sizeof(cmd), "%ds", test);
    drawText(Line2, "test");
}