#include "memory.h"

void storeColor(RGB color)
{
    EEPROM.write(RADDR, color.R);
    EEPROM.write(GADDR, color.G);
    EEPROM.write(BADDR, color.B);
    EEPROM.commit();
}

RGB readColor()
{
    RGB color;
    color.R = EEPROM.read(RADDR);
    color.G = EEPROM.read(GADDR);
    color.B = EEPROM.read(BADDR);
    return color;
}