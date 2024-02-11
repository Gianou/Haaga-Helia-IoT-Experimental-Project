#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <TFT_eSPI.h>

class GameObject
{
public:
    virtual void draw(TFT_eSprite &sprite) = 0;
    virtual void update() = 0;
    virtual ~GameObject() {} // Virtual destructor for proper polymorphic behavior
};

#endif
