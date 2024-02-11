#ifndef Player_H
#define Player_H

#include "InputManager.h"
#include <TFT_eSPI.h>
#include "GameObject.h"

class Player : public GameObject
{
public:
    Player(int initialX, int initialY, int playerWidth, int playerHeight);
    void draw(TFT_eSprite &sprite) override;
    void update() override;

    // Getters
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int x;
    int y;
    int width;
    int height;
    int speed;
    InputManager &inputManager;
};

#endif
