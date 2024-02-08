#ifndef Screen_H
#define Screen_H

#include <TFT_eSPI.h>
#include "Renderable.h"
#include "InputManager.h"

class Screen : public Renderable
{
public:
    Screen();
    void begin();
    void draw(TFT_eSPI &tft) override;
    TFT_eSPI &getTFT();

private:
    TFT_eSPI tft;
};

#endif
