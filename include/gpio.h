#ifndef _GPIO_H
#define _GPIO_H

#include <Arduino.h>

// PWM properties
#define FREQ 1000
#define RESOLUTION 8
#define RCHANNEL 0
#define GCHANNEL 3
#define BCHANNEL 5

// IO Pins
#define RPIN 16
#define GPIN 18
#define BPIN 17

void initGPIO();

#endif