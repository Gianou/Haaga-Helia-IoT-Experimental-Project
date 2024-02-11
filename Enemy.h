#ifndef Enemy_H
#define Enemy_H

#include "GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(int x, int y, int width, int height, int speed);
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void updateRightToLeft();
    void updateErratic();

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
};

#endif