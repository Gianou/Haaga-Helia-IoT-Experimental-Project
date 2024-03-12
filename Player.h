#ifndef Player_H
#define Player_H

#include "InputManager.h"
#include "SceneManager.h"
#include "EnemyManager.h"
#include "ScoreManager.h"
#include <TFT_eSPI.h>
#include "GameObject.h"
#include "ship.h"

class Player : public GameObject
{
public:
    Player(int initialX, int initialY, int playerWidth, int playerHeight);
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void takeHit();
    void reset();
    // Getters
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int x;
    int y;
    int newY;
    int width;
    int height;
    int speed;
    int life;
    boolean invincible;
    int invincibleCounter;
    int invincibleDuration;
    int score;

    int initialX;
    int initialY;
    int initialLife;
    int initialScore;

    InputManager &inputManager;
};

#endif
