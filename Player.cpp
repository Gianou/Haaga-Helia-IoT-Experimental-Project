#include "Player.h"

Player::Player(int initialX, int initialY, int playerWidth, int playerHeight)
    : x(initialX), y(initialY), width(playerWidth), height(playerHeight), speed(1), inputManager(InputManager::getInstance())
{
    // Constructor code if needed
}

void Player::update()
{
    // Get joystick values
    int joystickX = inputManager.getJoystickXValue();
    int joystickY = inputManager.getJoystickYValue();

    // Map joystick values to a range of -100 to 100
    int mappedJoystickX = map(joystickX, 2000, 1900, -100, 100);
    int mappedJoystickY = map(joystickY, 2000, 1900, -100, 100);

    // Handle player movement based on mapped joystick values
    x += speed * mappedJoystickX / 100; // Normalize to -1 to 1
    y += speed * mappedJoystickY / 100; // Normalize to -1 to 1

    // Add additional player update logic as needed
    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }
    if (x > 160 - width)
    {
        x = 160 - width;
    }
    if (y > 128 - height)
    {
        y = 128 - height;
    }
}

void Player::draw(TFT_eSPI &tft)
{
    // Draw the player as a rectangle
    tft.fillRect(x, y, width, height, TFT_RED); // Adjust color as needed

    // Add more drawing code as needed
}
