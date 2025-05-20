#include "LcdHandler.h"

SoftwareSerial LcdSerial(-1, PIN_LCD_DATA);

void initLcd()
{
  LcdSerial.begin(9600);         // Connect default speed
  sendLcdCommand("baud=115200"); // Change speed
  LcdSerial.begin(115200);       // Connect new speed
}

void sendLcdCommand(const char *cmd)
{
  LcdSerial.print(cmd);
  LcdSerial.write(0xFF); 
  LcdSerial.write(0xFF);
  LcdSerial.write(0xFF); // Save memory without loop
}

void drawImage(byte elementId, byte imageId)
{
  char cmd[18]; 
  snprintf(cmd, sizeof(cmd), "p%d.pic=\"%s\"", (int)elementId, imageId);
  sendLcdCommand(cmd);
}

void drawText(Line line, const char *msg)
{
  char cmd[24]; 
  snprintf(cmd, sizeof(cmd), "t%d.txt=\"%s\"", (int)line, msg);
  Serial.println(cmd);
  sendLcdCommand(cmd);
}