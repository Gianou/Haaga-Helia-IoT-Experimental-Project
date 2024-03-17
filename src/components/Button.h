#ifndef Button_H
#define Button_H

#include <Arduino.h>

class Button
{
public:
    Button(uint8_t pin);
    void begin();
    void update();
    int getValue();

private:
    uint8_t pin;
    int value;
};

#endif
