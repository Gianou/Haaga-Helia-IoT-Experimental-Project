#ifndef Enemy_Manager_H
#define Enemy_Manager_H

#include "GameObject.h"
#include "Enemy.h"
#include <vector>

class EnemyManager : public GameObject
{
public:
    static EnemyManager &getInstance();
    void draw(TFT_eSprite &sprite) override;
    void update() override;
    void addGameObject(Enemy *gameObject);
    void removeGameObject(Enemy *gameObject);
    const std::vector<Enemy *> &getEnemies() const;
    void reset();

private:
    EnemyManager(); // Private constructor to prevent external instantiation
    std::vector<Enemy *> enemies;
};

#endif