#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <TFT_eSPI.h>

class Renderable
{
public:
    virtual void draw(TFT_eSprite &sprite) = 0;
    virtual ~Renderable() {} // Virtual destructor for proper polymorphic behavior
};

#endif