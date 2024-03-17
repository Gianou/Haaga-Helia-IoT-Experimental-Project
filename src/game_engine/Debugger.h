#ifndef Debugger_H
#define Debugger_H

#include "InputManager.h"
#include "CollisionManager.h"
#include "GameObject.h"
#include "SceneManager.h"

class Debugger : public GameObject
{
public:
    Debugger(int x, int y, CollisionManager &collisionManager);
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    boolean getIsVisible();
    void setIsVisible(boolean visible);

private:
    int x;
    int y;
    boolean isVisible;
    InputManager &inputManager;
    CollisionManager &collisionManager;
};
#endif