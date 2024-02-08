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
    void draw(TFT_eSPI &tft) override; // Pass a reference to the TFT_eSPI object

private:
    int x;
    int y;
    int width;
    int height;
    int speed;
    InputManager &inputManager; // Reference to InputManager singleton
};

#endif
