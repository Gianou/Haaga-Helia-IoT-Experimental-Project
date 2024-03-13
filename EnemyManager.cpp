#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
    int speed = 8;
    Enemy *enemy1 = new Enemy(158, 40, 12, 12, speed);
    Enemy *enemy2 = new Enemy(158, 80, 12, 12, speed);
    Enemy *enemy3 = new Enemy(158, 0, 12, 12, speed);
    Enemy *enemy4 = new Enemy(158, 100, 12, 12, speed);

    addGameObject(enemy1);
    addGameObject(enemy2);
    addGameObject(enemy3);
    addGameObject(enemy4);
    // addGameObject(enemy5);
    // addGameObject(enemy6);

    numberOfEnemies = 1;
}

EnemyManager &EnemyManager::getInstance()
{
    static EnemyManager instance; // This ensures that only one instance exists
    return instance;
}

void EnemyManager::draw(TFT_eSprite &sprite)
{
    for (int i = 0; i < numberOfEnemies; i++)
    {
        enemies[i]->draw(sprite);
    }
}

void EnemyManager::update()
{

    ScoreManager &scoreManager = ScoreManager::getInstance();
    if (scoreManager.getScore() % 80 == 0 && numberOfEnemies < 3)
    {
        numberOfEnemies++;
    }
    for (int i = 0; i < numberOfEnemies; i++)

    {
        enemies[i]->update();
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

void EnemyManager::reset()
{
    numberOfEnemies = 1;
    for (Enemy *enemy : enemies)
    {
        enemy->reset();
    }
}

const std::vector<Enemy *> &EnemyManager::getEnemies() const
{
    return enemies;
}
