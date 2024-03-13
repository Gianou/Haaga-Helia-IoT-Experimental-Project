#ifndef TUTO_ANIMATION_H
#define TUTO_ANIMATION_H

#include "GameObject.h"
#include "Tuto_Sonar1.h"
#include "Tuto_Sonar2.h"

class TutoAnimation : public GameObject
{
public:
    void draw(TFT_eSprite &sprite) override;
    void update() override;

private:
};

#endif