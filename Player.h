#ifndef Player_H
#define Player_H

#include "InputManager.h"
#include <TFT_eSPI.h> // Include the library for the display
#include "Renderable.h"

class Player : public Renderable
{
public:
    Player(int initialX, int initialY, int playerWidth, int playerHeight);
    void update();
    void draw(TFT_eSprite &sprite) override;

private:
    int x;
    int y;
    int width;
    int height;
    int speed;
    InputManager &inputManager;
};

#endif
