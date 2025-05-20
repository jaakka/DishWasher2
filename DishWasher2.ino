#include "Values.h"
#include "Pins.h"
#include "LcdHandler.h"
#include <Arduino.h>

byte currentProgram = PROGRAM_MENU;
static volatile byte lastEncoded = 0;
static volatile byte pos = 0;

void initRelays()
{
    pinMode(PIN_RELAY_HEAT, OUTPUT);
    pinMode(PIN_RELAY_PUMP, OUTPUT);
    pinMode(PIN_RELAY_VALVE, OUTPUT);
    pinMode(PIN_RELAY_WASH, OUTPUT);
    pinMode(PIN_RELAY_POWER, OUTPUT);
    pinMode(PIN_RELAY_SOAP, OUTPUT);
}

void handleEncoder()
{
    byte MSB = digitalRead(ENCODER_RIGHT_PIN);
    byte LSB = digitalRead(ENCODER_LEFT_PIN);
    byte encoded = (MSB << 1) | LSB;
    byte sum = (lastEncoded << 2) | encoded;

    if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
    {
        pos++;
    }

    if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
    {
        pos--;
    }

    lastEncoded = encoded;
}

void initControls()
{
    pinMode(ENCODER_RIGHT_PIN, INPUT_PULLUP);
    pinMode(ENCODER_LEFT_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(ENCODER_RIGHT_PIN), handleEncoder, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT_PIN), handleEncoder, CHANGE);
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
    // Serial.begin(115200);
    initLcd();
    initRelays();
    initControls();
    intro();
}

void loop()
{
    handleMenu();
}

void handleMenu()
{
    static byte lastSteps = 0;
    if (pos != lastSteps)
    {
        if ((byte)(pos - lastSteps) < 128)
        {
            drawText(LCD_TEXT_POS_CENTER_BOTTOM, "left");
        }
        else
        {
            drawText(LCD_TEXT_POS_CENTER_BOTTOM, "right");
        }
        lastSteps = pos;
    }
}
