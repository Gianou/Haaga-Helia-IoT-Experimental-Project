#include "Debugger.h"
#include "InputManager.h"

Debugger::Debugger(int x, int y, CollisionManager &collisionManager)
    : x(x), y(y), isVisible(true), collisionManager(collisionManager), inputManager(InputManager::getInstance())
{
}

void Debugger::draw(TFT_eSprite &sprite)
{
    if (isVisible)
    {
        // INPUTS
        int ln = 9;
        sprite.drawString("Yell : " + String(inputManager.getYellowButtonValue()), x, y);
        sprite.drawString("Blue : " + String(inputManager.getBlueButtonValue()), x, y + ln);
        sprite.drawString("X : " + String(inputManager.getJoystickXValue()), x, y + 2 * ln);
        sprite.drawString("Y : " + String(inputManager.getJoystickYValue()), x, y + 3 * ln);

        // COLLISIONS
        sprite.drawString("Cols : " + String(collisionManager.getIsColliding()), 80, 4);
    }
}

void Debugger::update()
{
    // Toggle visibility
    if (!inputManager.getBlueButtonValue() & !inputManager.getYellowButtonValue())
    {
        isVisible = !isVisible;
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
