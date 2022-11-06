#ifndef _LED_H
#define _LED_H

typedef unsigned char BYTE;

typedef struct
{
    BYTE R;
    BYTE G;
    BYTE B;
} RGB;

void withTiming(RGB from, RGB to, unsigned int ms);
void setColor(RGB color);

#endif