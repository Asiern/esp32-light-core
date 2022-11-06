#include "gpio.h"

void initGPIO()
{
    ledcSetup(RCHANNEL, FREQ, RESOLUTION);
    ledcSetup(GCHANNEL, FREQ, RESOLUTION);
    ledcSetup(BCHANNEL, FREQ, RESOLUTION);
    ledcAttachPin(RPIN, RCHANNEL);
    ledcAttachPin(GPIN, GCHANNEL);
    ledcAttachPin(BPIN, BCHANNEL);
}