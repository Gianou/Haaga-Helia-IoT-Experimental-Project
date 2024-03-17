#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "EnemyManager.h"

class CollisionManager : public GameObject
{
public:
    CollisionManager(Player &player);
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void checkCollisions();
    boolean getIsColliding();

private:
    Player &player;
    boolean isColliding;
};

#endif