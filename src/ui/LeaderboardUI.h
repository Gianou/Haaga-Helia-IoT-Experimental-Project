#ifndef LEADERBOARD_UI_H
#define LEADERBOARD_UI_H

#include "../game_engine/GameObject.h"
#include "../game_engine/SceneManager.h"
#include "../game_engine/InputManager.h"
#include "../network/ConnexionManager.h"
#include <array>

class LeaderboardUI : public GameObject
{

public:
    LeaderboardUI();
    void update();
    void draw(TFT_eSprite &sprite);

private:
    std::array<String, 10> _lines;
    bool _isConnected;
};

#endif