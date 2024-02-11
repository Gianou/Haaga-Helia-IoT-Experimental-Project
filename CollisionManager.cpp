#include "CollisionManager.h"

CollisionManager::CollisionManager(Player &player, Enemy &enemy)
    : player(player), enemy(enemy), isColliding(false)
{
}

void CollisionManager::draw(TFT_eSprite &sprite)
{
}

void CollisionManager::update()
{
    checkCollisions();
}

void CollisionManager::checkCollisions()
{
    for (int i = 0; i < 2; i++)
    {
        if (player.getX() < enemy.getX() + enemy.getWidth() &&
            player.getX() + player.getWidth() > enemy.getX() &&
            player.getY() < enemy.getY() + enemy.getHeight() &&
            player.getY() + player.getHeight() > enemy.getY())
        {
            isColliding = true;
            return;
        }
    }
    isColliding = false;
}

boolean CollisionManager::getIsColliding()
{
    return isColliding;
}