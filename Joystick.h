#ifndef Joystick_H
#define Joystick_H

#include <Arduino.h>

class Joystick
{
public:
    Joystick(uint8_t vrx, uint8_t vry);
    void update();
    int getXValue();
    int getYValue();

private:
    uint8_t vrx;
    uint8_t vry;
    uint16_t xValue;
    uint16_t yValue;
};

#endif