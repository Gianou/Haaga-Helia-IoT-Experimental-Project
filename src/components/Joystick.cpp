#include "Joystick.h"

Joystick::Joystick(uint8_t vrx, uint8_t vry) : vrx(vrx), vry(vry) {}

void Joystick::update()
{
    xValue = analogRead(vrx);
    yValue = analogRead(vry);
}

int Joystick::getXValue()
{
    return xValue;
}
int Joystick::getYValue()
{
    return yValue;
}