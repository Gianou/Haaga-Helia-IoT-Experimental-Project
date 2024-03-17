#ifndef START_UI_H
#define START_UI_H

#include "../game_engine/GameObject.h"
#include "../game_engine/SceneManager.h"
#include "../game_engine/InputManager.h"

class StartUI : public GameObject
{

public:
    StartUI();
    void update();
    void draw(TFT_eSprite &sprite);

private:
    bool moveYAxis;
    int currentCharYIndex;
    void handleInput();
};

#endif