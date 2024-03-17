#include "GameEngine.h"

GameEngine::GameEngine()
{
}

void GameEngine::draw(TFT_eSprite &sprite)
{
    sprite.fillRect(0, 0, 158, 128, TFT_BLACK);
    for (GameObject *gameObject : gameObjects)
    {
        gameObject->draw(sprite);
    }
}

void GameEngine::update()
{
    for (GameObject *gameObject : gameObjects)
    {
        gameObject->update();
    }
}

void GameEngine::addGameObject(GameObject *gameObject)
{
    gameObjects.push_back(gameObject);
}

void GameEngine::removeGameObject(GameObject *gameObject)
{
    // Assuming you have a way to identify and remove the GameObject.
    // Implementation depends on your specific requirements.
    // This might involve searching and erasing from the vector.
}
