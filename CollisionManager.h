#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include "Player.h"
#include "Enemy.h"

class CollisionManager : public GameObject
{
public:
    CollisionManager(Player &player, Enemy &enemy);
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void checkCollisions();
    boolean getIsColliding();

private:
    Player &player;
    Enemy &enemy;
    boolean isColliding;
};

#endif