#include "SceneManager.h"

SceneManager::SceneManager() : index(0)
{
}

SceneManager &SceneManager::getInstance()
{
    static SceneManager instance; // This ensures that only one instance exists
    return instance;
}

void SceneManager::setIndex(int index)
{
    // reset the boolean used by the LeaderboardUI to not get Firebase data on every frame
    isFirstFrameOfLeaderboard = true;
    this->index = index;
}

bool SceneManager::getIsFirstFrameOfLeaderboard()
{
    return isFirstFrameOfLeaderboard;
}

void SceneManager::setIsFirstFrameOfLeaderboard(bool newIsFirstFrameOfLeaderboard)
{
    isFirstFrameOfLeaderboard = newIsFirstFrameOfLeaderboard;
}

void SceneManager::draw(TFT_eSprite &sprite)
{
    if (index < gameObjects.size())
    {
        gameObjects[index]->draw(sprite);
    }
    else
    {
        // Handle the case where index is out of bounds
        Serial.println("Index out of bounds!");
    }
}

void SceneManager::update()
{
    if (index < gameObjects.size())
    {
        gameObjects[index]->update();
    }
    else
    {
        // Handle the case where index is out of bounds
        Serial.println("Index out of bounds!");
    }
}

void SceneManager::addGameObject(GameObject *gameObject)
{
    gameObjects.push_back(gameObject);
}

void SceneManager::removeGameObject(GameObject *gameObject)
{
    // Assuming you have a way to identify and remove the GameObject.
    // Implementation depends on your specific requirements.
    // This might involve searching and erasing from the vector.
}