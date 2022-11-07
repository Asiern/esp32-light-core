#ifndef _MEMORY_H
#define _MEMORY_H
#include <EEPROM.h>
#include "led.h"

#define EEPROM_SIZE sizeof(BYTE)

#define RADDR 0
#define GADDR 1
#define BADDR 2

void storeColor(RGB color);
RGB readColor();

#endif