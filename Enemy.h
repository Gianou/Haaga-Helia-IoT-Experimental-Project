#ifndef Enemy_H
#define Enemy_H

#include "GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(int x, int y, int width, int height, int speed);
    void draw(TFT_eSprite &sprite) override;
    void update() override;

private:
    int x;
    int y;
    int width;
    int height;
    int speed;
};

#endif