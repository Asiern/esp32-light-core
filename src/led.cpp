#include "led.h"
#include <math.h>
#include <algorithm>
#include <Arduino.h>
#include "gpio.h"

void withTiming(RGB from, RGB to, unsigned int ms)
{
    RGB diff, status;
    diff.R = abs(from.R - to.R);
    diff.G = abs(from.G - to.G);
    diff.B = abs(from.B - to.B);
    status.R = from.R;
    status.G = from.G;
    status.B = from.B;

    while (status.R != to.R || status.G != to.G || status.B != to.B)
    {
        Serial.printf("FROM [%d,%d,%d] TO [%d,%d,%d]. Diff: [%d,%d,%d], Status: [%d,%d,%d]\n", from.R, from.G, from.B, to.R, to.G, to.B, diff.R, diff.G, diff.B, status.R, status.G, status.B);
        // Update status value
        status.R = status.R + 1 > to.R ? to.R : status.R + 1;
        status.G = status.G + 1 > to.G ? to.G : status.G + 1;
        status.B = status.B + 1 > to.B ? to.B : status.B + 1;
        // Set color
        setColor(status);
        delay(ms / std::max(diff.R, std::max(diff.G, diff.B)));
    }
}

void setColor(RGB color)
{
    ledcWrite(RCHANNEL, abs(color.R - 255));
    ledcWrite(GCHANNEL, abs(color.G - 255));
    ledcWrite(BCHANNEL, abs(color.B - 255));
}