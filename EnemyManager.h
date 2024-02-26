#ifndef Enemy_Manager_H
#define Enemy_Manager_H

#include "GameObject.h"
#include "Enemy.h"
#include <vector>

class EnemyManager : public GameObject
{
public:
    EnemyManager();
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void addGameObject(Enemy *gameObject);
    void removeGameObject(Enemy *gameObject);
    const std::vector<Enemy *> &getEnemies() const;

private:
    std::vector<Enemy *> enemies;
};

#endif