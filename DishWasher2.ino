#include "Values.h"
#include "LcdHandler.h"
#include <Arduino.h>

byte currentProgram = PROGRAM_MENU;

void initRelays()
{
    pinMode(PIN_RELAY_HEAT, OUTPUT);
    pinMode(PIN_RELAY_PUMP, OUTPUT);
    pinMode(PIN_RELAY_VALVE, OUTPUT);
    pinMode(PIN_RELAY_WASH, OUTPUT);
    pinMode(PIN_RELAY_POWER, OUTPUT);
    pinMode(PIN_RELAY_SOAP, OUTPUT);
}

void intro()
{
    clearLcd();
    drawImage(LCD_ICON_POS_LARGE_CENTER_ICON, LCD_ICON_LARGE_SOAP);
    drawText(LCD_TEXT_POS_CENTER_TOP, "DishWash2");
    drawText(LCD_TEXT_POS_CENTER_BOTTOM, "ECO-RAM");
    delay(1000);
}

void setup()
{
    //Serial.begin(115200);
    initLcd();
    initRelays();
    intro();
}

void loop()
{
    handleMenu();
}

void handleMenu() 
{
    
}