#include "Button.h"

Button::Button(uint8_t pin) : pin(pin) {}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

void Button::update()
{
    digitalRead(pin);
}

int Button::getValue()
{
    return value;
}
