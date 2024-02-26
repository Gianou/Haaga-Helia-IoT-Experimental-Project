#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
    Enemy *enemy1 = new Enemy(100, 50, 12, 12, 10);
    Enemy *enemy2 = new Enemy(160, 90, 12, 12, 10);
    Enemy *enemy3 = new Enemy(220, 10, 12, 12, 10);

    addGameObject(enemy1);
    addGameObject(enemy2);
    addGameObject(enemy3);
}

void EnemyManager::draw(TFT_eSprite &sprite)
{
    for (Enemy *enemy : enemies)
    {
        enemy->draw(sprite);
    }
}

void EnemyManager::update()
{
    for (Enemy *enemy : enemies)
    {
        enemy->update();
    }
}

void EnemyManager::addGameObject(Enemy *gameObject)
{
    enemies.push_back(gameObject);
}

void EnemyManager::removeGameObject(Enemy *gameObject)
{
    // Check if this works (chatGPT stuff)
    // Remove the specified enemy from the vector
    auto it = std::find(enemies.begin(), enemies.end(), gameObject);
    if (it != enemies.end())
    {
        enemies.erase(it);
        delete gameObject; // Assuming you are responsible for memory management
    }
}

const std::vector<Enemy *> &EnemyManager::getEnemies() const
{
    return enemies;
}
