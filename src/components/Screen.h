#ifndef Screen_H
#define Screen_H

#include <TFT_eSPI.h>
#include "../game_engine/GameObject.h"
// #include "../game_engine/InputManager.h"
#include "../network/ConnexionManager.h"
// #include "config.h"

class Screen : public GameObject
{
public:
    Screen();
    void begin();
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    TFT_eSPI &getTFT();
    TFT_eSprite &getSprite();

private:
    TFT_eSPI tft;
    TFT_eSprite sprite;
};

#endif
