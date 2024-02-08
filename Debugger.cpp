#include "Debugger.h"
#include "InputManager.h"

Debugger::Debugger(int x, int y)
    : x(x), y(y), isVisible(true), inputManager(InputManager::getInstance())
{
}

void Debugger::draw(TFT_eSPI &tft)
{
    if (isVisible)
    {
        int ln = 9;
        // Draw the debugger content as needed
        // For example, display joystick values or other debug information
        tft.setCursor(x, y, 1);
        tft.setTextColor(TFT_WHITE);
        tft.printf("Yell: %d\n", inputManager.getYellowButtonValue());
        tft.setCursor(x, y + ln, 1);
        tft.printf("Blue: %d\n", inputManager.getBlueButtonValue());
        tft.setCursor(x, y + 2 * ln, 1);
        tft.printf("X: %d\n", inputManager.getJoystickXValue());
        tft.setCursor(x, y + 3 * ln, 1);
        tft.printf("Y: %d\n", inputManager.getJoystickYValue());
        // Add more debug information or visualization as needed
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
