#include "CollisionManager.h"

CollisionManager::CollisionManager(Player &player, Enemy &enemy)
    : player(player), enemy(enemy), collisionCounter(0)
{
}

void CollisionManager::draw(TFT_eSprite &sprite)
{
    sprite.drawString("Cols : " + String(collisionCounter), 80, 4);
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
            collisionCounter++;
        }
    }
}