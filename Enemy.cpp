#include "Enemy.h"

Enemy::Enemy(int x, int y, int width, int height, int speed)
    : x(x), y(y), width(width), height(height), speed(speed)
{
}

void Enemy::update()
{
    updateRightToLeft();
}

void Enemy::draw(TFT_eSprite &sprite)
{
    sprite.fillRect(x, y, width, height, TFT_BLUE);
}

void Enemy::updateErratic()
{
    // Erratic enemy movements for demonstration

    // Generate random movement
    int randomX = random(-1, 2); // Random value between -1, 0, and 1
    int randomY = random(-1, 2);

    x += speed * randomX;
    y += speed * randomY;

    // Ensure the enemy stays within the screen boundaries
    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    if (x > 160 - width)
        x = 160 - width;
    if (y > 128 - height)
        y = 128 - height;
}

void Enemy::updateRightToLeft()
{
    x -= speed;

    if (x + width < 0)
    {
        x = 160;
        y = random(0, 128 - height);
    }
}