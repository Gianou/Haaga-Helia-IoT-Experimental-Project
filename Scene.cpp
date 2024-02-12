#include "Scene.h"

Scene::Scene()
{
}

void Scene::draw(TFT_eSprite &sprite)
{

    for (GameObject *gameObject : gameObjects)
    {
        gameObject->draw(sprite);
    }
}

void Scene::update()
{
    for (GameObject *gameObject : gameObjects)
    {
        gameObject->update();
    }
}

void Scene::addGameObject(GameObject *gameObject)
{
    gameObjects.push_back(gameObject);
}

void Scene::removeGameObject(GameObject *gameObject)
{
    // Assuming you have a way to identify and remove the GameObject.
    // Implementation depends on your specific requirements.
    // This might involve searching and erasing from the vector.
}
