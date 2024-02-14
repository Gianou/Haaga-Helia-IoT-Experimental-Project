#ifndef GAME_OVER_UI_H
#define GAME_OVER_UI_H

#include "GameObject.h"
#include "SceneManager.h"
#include "InputManager.h"

class GameOverUI : public GameObject
{

public:
    GameOverUI();
    void update();
    void draw(TFT_eSprite &sprite);

private:
};

#endif