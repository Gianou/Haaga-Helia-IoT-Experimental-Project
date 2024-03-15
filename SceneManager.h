#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <vector>
#include "GameObject.h"

class SceneManager : public GameObject
{
public:
    static SceneManager &getInstance();

    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void addGameObject(GameObject *gameObject);
    void removeGameObject(GameObject *gameObject);
    void setIndex(int index);
    bool getIsFirstFrameOfLeaderboard();
    void setIsFirstFrameOfLeaderboard(bool newIsFirstFrameOfLeaderboard);

private:
    std::vector<GameObject *>
        gameObjects;
    int index;
    bool isFirstFrameOfLeaderboard = true;

    SceneManager();                                // Private constructor to enforce Singleton pattern
    SceneManager(const SceneManager &) = delete;   // Disallow copy constructor
    void operator=(const SceneManager &) = delete; // Disallow assignment operator
};

#endif