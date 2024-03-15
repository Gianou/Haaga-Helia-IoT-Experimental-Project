#include "Debugger.h"
#include "InputManager.h"

Debugger::Debugger(int x, int y, CollisionManager &collisionManager)
    : x(x), y(y), isVisible(false), collisionManager(collisionManager), inputManager(InputManager::getInstance())
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
        sprite.drawString("Dist : " + String(inputManager.getSonarDistance()), x, y + 4 * ln);

        // COLLISIONS
        sprite.drawString("Cols : " + String(collisionManager.getIsColliding()), 80, 4);

        // GYROSCOPE ACCELERATION
        sprite.drawString("Gyro X : " + String(inputManager.getGyroscopeAXValue()), x, y + 5 * ln);
        sprite.drawString("Gyro Y : " + String(inputManager.getGyroscopeAYValue()), x, y + 6 * ln);
        sprite.drawString("Gyro Z : " + String(inputManager.getGyroscopeAZValue()), x, y + 7 * ln);

        // LEADERBOARD
        SceneManager &sceneManager = SceneManager::getInstance();
        sprite.drawString("LB 1st frame : " + String(sceneManager.getIsFirstFrameOfLeaderboard()), x, y + 8 * ln);
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
