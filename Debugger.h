#ifndef Debugger_H
#define Debugger_H

#include "InputManager.h"
#include "GameObject.h"

class Debugger : public GameObject
{
public:
    Debugger(int x, int y);
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    boolean getIsVisible();
    void setIsVisible(boolean visible);

private:
    int x;
    int y;
    boolean isVisible;
    InputManager &inputManager;
};
#endif