#include "Screen.h"

Screen::Screen() : tft(TFT_eSPI()) {}

void Screen::begin()
{
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.drawRect(0, 0, tft.width(), tft.height(), TFT_GREEN);

    // Set "cursor" at top left corner of display (0,0) and select font 4
    tft.setCursor(0, 4, 4);
    // Set the font colour to be white with a black background
    tft.setTextColor(TFT_WHITE);
    tft.println("Hello World!");
}

void Screen::draw()
{
    tft.fillScreen(TFT_BLACK); // To delete the previous frame

    tft.setCursor(0, 4, 2);
    tft.setTextColor(TFT_WHITE);

    // Retrieve the InputManager instance
    InputManager &inputManager = InputManager::getInstance();
    inputManager.update(); // Make sure to update the inputManager before getting values

    // Get input values
    int blueButtonValue = inputManager.getBlueButtonValue();
    int yellowButtonValue = inputManager.getYellowButtonValue();
    int joystickXValue = inputManager.getJoystickXValue();
    int joystickYValue = inputManager.getJoystickYValue();

    // Print input values on the screen
    tft.print("Blue : ");
    tft.println(blueButtonValue);

    tft.print("Yellow : ");
    tft.println(yellowButtonValue);

    tft.print("X: ");
    tft.println(joystickXValue);

    tft.print("Y: ");
    tft.println(joystickYValue);
}

TFT_eSPI &Screen::getTFT()
{
    return tft;
}
