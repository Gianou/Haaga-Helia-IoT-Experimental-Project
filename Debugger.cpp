#include "Debugger.h"
#include "InputManager.h"

Debugger::Debugger(int x, int y)
    : x(x), y(y), isVisible(true), inputManager(InputManager::getInstance())
{
}

void Debugger::draw(TFT_eSprite &sprite)
{
    if (isVisible)
    {
        int ln = 9;

        sprite.drawString("Yell : " + String(inputManager.getYellowButtonValue()), x, y);
        sprite.drawString("Blue : " + String(inputManager.getBlueButtonValue()), x, y + ln);
        sprite.drawString("X : " + String(inputManager.getJoystickXValue()), x, y + 2 * ln);
        sprite.drawString("Y : " + String(inputManager.getJoystickYValue()), x, y + 3 * ln);
    }
}

boolean Debugger::getIsVisible()
{
    return isVisible;
}

void Debugger::setIsVisible(boolean visible)
{
    isVisible = visible;
}
