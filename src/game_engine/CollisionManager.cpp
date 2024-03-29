#include "CollisionManager.h"

CollisionManager::CollisionManager(Player &player)
    : player(player), isColliding(false)
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
    EnemyManager &enemyManager = EnemyManager::getInstance();
    const std::vector<Enemy *> &enemies = enemyManager.getEnemies();

    for (const Enemy *enemy : enemies)
    {
        if (player.getX() < enemy->getX() + enemy->getWidth() &&
            player.getX() + player.getWidth() > enemy->getX() &&
            player.getY() < enemy->getY() + enemy->getHeight() &&
            player.getY() + player.getHeight() > enemy->getY())
        {
            isColliding = true;
            player.takeHit();
            return;
        }
    }
    isColliding = false;
}

boolean CollisionManager::getIsColliding()
{
    return isColliding;
}