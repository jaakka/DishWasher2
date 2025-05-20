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
  delay(10);
}

void drawImage(byte elementId, byte imageId)
{
  char cmd[18]; 
  snprintf(cmd, sizeof(cmd), "p%d.pic=%d", (int)elementId, (int)imageId);
  sendLcdCommand(cmd);
}

void drawText(byte line, const char *msg)
{
  char cmd[24]; 
  snprintf(cmd, sizeof(cmd), "t%d.txt=\"%s\"", (int)line, msg);
  sendLcdCommand(cmd);
}

void clearLcd()
{
  drawImage(LCD_BACKGROUND_POS_RIGHT_TOP, LCD_BACKGROUND_RIGHT_TOP_EMPTY);
  drawImage(LCD_BACKGROUND_POS_LEFT_TOP, LCD_BACKGROUND_LEFT_TOP_EMPTY);
  drawImage(LCD_BACKGROUND_POS_RIGHT_BOTTOM, LCD_BACKGROUND_RIGHT_BOTTOM_EMPTY);
  drawImage(LCD_BACKGROUND_POS_LEFT_BOTTOM, LCD_BACKGROUND_LEFT_BOTTOM_EMPTY);
}