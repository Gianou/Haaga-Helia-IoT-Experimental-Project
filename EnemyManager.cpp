#include "EnemyManager.h"

/*
1. add isTutoPhase
2. add tutoCounter
3. draw tuto thing -> array of new class?
*/
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
    isEnemyOnHold = false;
    isTutoPhase = false;
}

EnemyManager &EnemyManager::getInstance()
{
    static EnemyManager instance; // This ensures that only one instance exists
    return instance;
}

void EnemyManager::draw(TFT_eSprite &sprite)
{

    if (isTutoPhase)
    {
        // drawCurrentTuto();
        sprite.drawString("Do a barrel roll", 80, 40);
        return;
    }

    for (int i = 0; i < numberOfEnemies; i++)
    {
        enemies[i]->draw(sprite);
    }
}

void EnemyManager::update()
{

    if (isTutoPhase)
    {
        tutoPhaseCounter++;
        if (tutoPhaseCounter >= tutoDuration)
        {
            reset();
            numberOfEnemies = 1;
            isTutoPhase = false;
            isEnemyOnHold = false;
            tutoPhaseCounter = 0;
            // Say that we need to change the control
        }
        return;
    }

    ScoreManager &scoreManager = ScoreManager::getInstance();
    if (scoreManager.getScore() % 80 == 0)
    {
        if (numberOfEnemies < 3)
        {
            numberOfEnemies++;
        }
        else
        {
            isEnemyOnHold = true;
        }
    }

    for (int i = 0; i < numberOfEnemies; i++)

    {
        if (!isEnemyOnHold)
        {
            enemies[i]->update();
        }
        else
        {
            if ((enemies[i]->getX() + enemies[i]->getWidth() > 8)) // needs to be fine tuned
            {
                enemies[i]->update();
                if (i = 3)
                {
                    // flag last enemy has reached end of screen
                    isTutoPhase = true;
                }
            }
        }
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
