#include "Player.h"

Player::Player(int initialX, int initialY, int playerWidth, int playerHeight)
    : x(initialX),
      y(initialY),
      width(playerWidth),
      height(playerHeight),
      speed(1),
      life(3),
      invincible(false),
      invincibleCounter(0),
      invincibleDuration(12),
      score(0),
      inputManager(InputManager::getInstance())
{
}

void Player::update()
{
    score++;
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

    // Invincibility stuff
    if (invincible)
    {
        invincibleCounter++;
        if (invincibleCounter >= invincibleDuration)
        {
            invincible = false;
            invincibleCounter = 0;
        }
        return;
    }
}

void Player::draw(TFT_eSprite &sprite)
{
    // Draw player
    if (invincible)
    {
        sprite.fillRect(x, y, width, height, TFT_WHITE);
    }
    else
    {
        sprite.fillRect(x, y, width, height, TFT_RED);
    }

    // Draw player's life
    for (int i = 0; i < life; i++)
    {
        sprite.fillCircle(10 + i * 15, 10, 5, TFT_RED);
    }
    // Draw score
    sprite.drawString(String(score), 138, 10);
}

void Player::takeHit()
{
    if (invincible)
    {
        return;
    }

    life--;
    invincible = true;
    if (life <= 0)
    {
        SceneManager &sceneManager = SceneManager::getInstance();
        sceneManager.setIndex(2);
    }
}
