#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <vector>
#include "GameObject.h"

class GameEngine : public GameObject
{
public:
    GameEngine();
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void addGameObject(GameObject *gameObject);
    void removeGameObject(GameObject *gameObject);

private:
    std::vector<GameObject *> gameObjects;
};

#endif
