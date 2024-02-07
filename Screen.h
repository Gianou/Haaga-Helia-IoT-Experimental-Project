#ifndef Screen_H
#define Screen_H

#include <TFT_eSPI.h>
#include "InputManager.h"

class Screen
{
public:
    Screen();
    void begin();
    void draw();

private:
    TFT_eSPI tft;
};

#endif
