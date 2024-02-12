#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "GameObject.h"

class Scene : public GameObject
{
public:
    Scene();
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void addGameObject(GameObject *gameObject);
    void removeGameObject(GameObject *gameObject);

private:
    std::vector<GameObject *> gameObjects;
};

#endif