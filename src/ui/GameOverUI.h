#ifndef GAME_OVER_UI_H
#define GAME_OVER_UI_H

#include "../game_engine/GameObject.h"
#include "../game_engine/SceneManager.h"
#include "../game_engine/InputManager.h"
#include "../game_engine/ScoreManager.h"
#include "../network/ConnexionManager.h"

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