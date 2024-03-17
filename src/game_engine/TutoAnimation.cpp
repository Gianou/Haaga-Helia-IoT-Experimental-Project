#include <Arduino.h>
#include "TutoAnimation.h"

TutoAnimation::TutoAnimation()
{
    // Constructor implementation, if needed
}

void TutoAnimation::update()
{
    counter++;
}

void TutoAnimation::draw(TFT_eSprite &sprite)
{

    if (gamePhaseCounter == 0)
    {
        drawJoystickTuto(sprite);
    }
    else if (gamePhaseCounter == 1)
    {
        drawSonarTuto(sprite);
    }
    else if (gamePhaseCounter == 2)
    {
        drawGyroTuto(sprite);
    }
}

void TutoAnimation ::setGamePhaseCounter(int newGamePhaseCounter)
{
    gamePhaseCounter = newGamePhaseCounter;
}

void TutoAnimation ::drawJoystickTuto(TFT_eSprite &sprite)
{
    sprite.drawString("Pilot the Ship", 50, 40);
    sprite.drawString("With the JOYSTICK!", 50, 50);
    if (counter % 12 <= 4)
    {
        sprite.pushImage(x, y, 27, 38, Tuto_Joystick1);
    }
    else if (counter % 12 <= 8)
    {
        sprite.pushImage(x, y, 27, 38, Tuto_Joystick2);
    }
    else if (counter % 12 <= 11)
    {
        sprite.pushImage(x, y, 27, 38, Tuto_Joystick3);
    }
}

void TutoAnimation ::drawSonarTuto(TFT_eSprite &sprite)
{
    sprite.drawString("Pilot the Ship", 50, 40);
    sprite.drawString("With the SONAR!", 50, 50);
    counter % 12 <= 6
        ? sprite.pushImage(x, y, 27, 38, Tuto_Sonar1)
        : sprite.pushImage(x, y, 27, 38, Tuto_Sonar2);
}

void TutoAnimation ::drawGyroTuto(TFT_eSprite &sprite)
{
    sprite.drawString("Pilot the Ship", 50, 40);
    sprite.drawString("With the Gyro!", 50, 50);
    if (counter % 12 <= 4)
    {
        sprite.pushImage(x, y, 27, 38, Tuto_Gyro1);
    }
    else if (counter % 12 <= 8)
    {
        sprite.pushImage(x, y, 27, 38, Tuto_Gyro2);
    }
    else if (counter % 12 <= 11)
    {
        sprite.pushImage(x, y, 27, 38, Tuto_Gyro3);
    }
}