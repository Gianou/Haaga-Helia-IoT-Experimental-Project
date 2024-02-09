#ifndef Debugger_H
#define Debugger_H

#include "InputManager.h"
#include "Renderable.h"

class Debugger : public Renderable
{
public:
    Debugger(int x, int y);
    void draw(TFT_eSprite &sprite) override;
    boolean getIsVisible();
    void setIsVisible(boolean visible);

private:
    int x;
    int y;
    boolean isVisible;
    InputManager &inputManager;
};
#endif