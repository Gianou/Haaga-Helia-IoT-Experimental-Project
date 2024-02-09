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
    void draw(TFT_eSprite &sprite) override;
    TFT_eSPI &getTFT();
    TFT_eSprite &getSprite();

private:
    TFT_eSPI tft;
    TFT_eSprite sprite;
};

#endif
