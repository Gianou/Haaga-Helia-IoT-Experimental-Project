#ifndef TUTO_ANIMATION_H
#define TUTO_ANIMATION_H

#include <TFT_eSPI.h>
#include "GameObject.h"

#include "Tuto_Sonar1.h"
#include "Tuto_Sonar2.h"
#include "Tuto_Joystick1.h"
#include "Tuto_Joystick2.h"
#include "Tuto_Joystick3.h"

class TutoAnimation : public GameObject
{
public:
    TutoAnimation();
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void setGamePhaseCounter(int newGamePhaseCounter);

private:
    int counter = 0;
    int gamePhaseCounter = 0;
};

#endif