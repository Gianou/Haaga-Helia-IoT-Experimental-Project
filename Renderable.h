#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <TFT_eSPI.h>

class Renderable
{
public:
    virtual void draw(TFT_eSPI &tft) = 0;
    virtual ~Renderable() {} // Virtual destructor for proper polymorphic behavior
};

#endif