#ifndef LEADERBOARD_UI_H
#define LEADERBOARD_UI_H

#include "GameObject.h"
#include "SceneManager.h"
#include "InputManager.h"

class LeaderboardUI : public GameObject
{

public:
    LeaderboardUI();
    void update();
    void draw(TFT_eSprite &sprite);

private:
};

#endif