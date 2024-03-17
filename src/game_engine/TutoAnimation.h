#ifndef TUTO_ANIMATION_H
#define TUTO_ANIMATION_H

#include <TFT_eSPI.h>
#include "GameObject.h"

#include "../sprites/Tuto_Sonar1.h"
#include "../sprites/Tuto_Sonar2.h"
#include "../sprites/Tuto_Joystick1.h"
#include "../sprites/Tuto_Joystick2.h"
#include "../sprites/Tuto_Joystick3.h"
#include "../sprites/Tuto_Gyro1.h"
#include "../sprites/Tuto_Gyro2.h"
#include "../sprites/Tuto_Gyro3.h"

class TutoAnimation : public GameObject
{
public:
    TutoAnimation();
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void setGamePhaseCounter(int newGamePhaseCounter);

private:
    int x = 70;
    int y = 60;
    int counter = 0;
    int gamePhaseCounter = 0;
    void drawJoystickTuto(TFT_eSprite &sprite);
    void drawSonarTuto(TFT_eSprite &sprite);
    void drawGyroTuto(TFT_eSprite &sprite);
};

#endif