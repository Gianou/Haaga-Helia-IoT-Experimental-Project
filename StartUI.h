#ifndef START_UI_H
#define START_UI_H

#include "GameObject.h"
#include "SceneManager.h"
#include "InputManager.h"

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