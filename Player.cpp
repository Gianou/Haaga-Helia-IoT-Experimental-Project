#include "Player.h"

Player::Player(int x, int y, int playerWidth, int playerHeight)
    : x(x),
      y(y),
      newY(y),
      width(playerWidth),
      height(playerHeight),
      speed(3),
      life(3),
      invincible(false),
      invincibleCounter(0),
      invincibleDuration(12),
      score(0),
      initialX(x),
      initialY(y),
      initialLife(life),
      inputManager(InputManager::getInstance())
{
}

void Player::moveShipWithSonar()
{
    float distance = inputManager.getSonarDistance();
    int max = 16; // 8 is too hard to control, the smaller the bigger the jitter, 18 is good but very far

    // Prevents jittering from incoherent inputs
    if (distance == 0 && distance >= max)
    {
        return;
    }

    // Place the ship on the screen according to hand position
    if (score % 2 == 0)
    {
        newY = (148 - height) - ((148 - height) / max * distance) + 20;
    }
    // Should prevent jumps
    int maxMovement = 100;
    // int minMovement = 4;
    int movement = abs(newY - y);

    if (movement < maxMovement)
    {
        y = newY;
    }
}

void Player::moveShipWithJoystick()
{
    int joystickY = inputManager.getJoystickYValue();
    int mappedJoystickY = map(joystickY, 2200, 1800, -100, 100);
    y += speed * mappedJoystickY / 200;
}

void Player::update()
{
    // Get joystick values
    int joystickX = inputManager.getJoystickXValue();
    int joystickY = inputManager.getJoystickYValue();
    boolean yell = inputManager.getYellowButtonValue();
    boolean blue = inputManager.getBlueButtonValue();
    EnemyManager &enemyManager = EnemyManager::getInstance();

    enemyManager.getGamePhaseCounter() % 2 == 1
        ? moveShipWithSonar()
        : moveShipWithJoystick();

    if (y < 0)
    {
        y = 0;
    }
    if (y > 128 - height)
    {
        y = 128 - height;
    }

    score++;
    // Save score
    ScoreManager &scoreManager = ScoreManager::getInstance();
    scoreManager.setScore(score);

    // GAME OVER
    if (life <= 0)
    {
        // Reset player and enemies
        EnemyManager &enemyManager = EnemyManager::getInstance();
        enemyManager.resetForNewGame();
        reset(); // must happen after the score is saved in ScoreManager
        SceneManager &sceneManager = SceneManager::getInstance();
        sceneManager.setIndex(2);
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
        // sprite.fillRect(x, y, width, height, TFT_RED);
        sprite.pushImage(x, y, 20, 20, Ship);
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
}

void Player::reset()
{
    x = initialX;
    y = initialY;
    life = initialLife;
    invincible = false;
    score = 0;
}
