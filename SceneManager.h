#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <vector>
#include "GameObject.h"

class SceneManager : public GameObject
{
public:
    SceneManager();
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void addGameObject(GameObject *gameObject);
    void removeGameObject(GameObject *gameObject);
    void setIndex(int index);

private:
    std::vector<GameObject *> gameObjects;
    int index;
};

#endif