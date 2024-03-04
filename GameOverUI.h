#ifndef GAME_OVER_UI_H
#define GAME_OVER_UI_H

#include "GameObject.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ConnexionManager.h"
#include "ScoreManager.h"

class GameOverUI : public GameObject
{

public:
    GameOverUI();
    void update();
    void draw(TFT_eSprite &sprite);

private:
    char alphabets[26];
    char nameInput[3];
    char userSelection[3];
    bool userChanged[3];
    bool moveXAxis;
    bool moveYAxis;
    int currentCharXIndex;
    int currentCharYIndex;
    void handleInput();
    void saveScoreToDB();
};

#endif