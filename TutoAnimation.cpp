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
    int x = 70;
    int y = 60;

    // if Sonar
    if (gamePhaseCounter % 2 == 1)
    {
        sprite.drawString("Pilot the Ship", 50, 40);
        sprite.drawString("With the SONAR!", 50, 50);
        counter % 12 <= 6
            ? sprite.pushImage(x, y, 27, 38, Tuto_Sonar1)
            : sprite.pushImage(x, y, 27, 38, Tuto_Sonar2);
    }
    else // Joystick
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
}

void TutoAnimation ::setGamePhaseCounter(int newGamePhaseCounter)
{
    gamePhaseCounter = newGamePhaseCounter;
}