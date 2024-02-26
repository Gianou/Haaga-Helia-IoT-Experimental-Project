#include "Player.h"

Player::Player(int initialX, int initialY, int playerWidth, int playerHeight)
    : x(initialX), y(initialY), width(playerWidth), height(playerHeight), speed(1), inputManager(InputManager::getInstance())
{
}

void Player::update()
{
    // Get joystick values
    int joystickX = inputManager.getJoystickXValue();
    int joystickY = inputManager.getJoystickYValue();
    boolean yell = inputManager.getYellowButtonValue();
    boolean blue = inputManager.getBlueButtonValue();

    // Map joystick values to a range of -100 to 100
    int mappedJoystickX = map(joystickX, 2000, 1900, -100, 100);
    int mappedJoystickY = map(joystickY, 2000, 1900, -100, 100);

    // Handle player movement based on mapped joystick values
    x += speed * mappedJoystickX / 200;
    y += speed * mappedJoystickY / 200;

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

void Player::draw(TFT_eSprite &sprite)
{
    sprite.fillRect(x, y, width, height, TFT_RED);
}
