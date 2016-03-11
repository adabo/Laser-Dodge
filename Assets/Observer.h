#pragma once
#include "Laser.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Observer
{
public:
    Observer();
    ~Observer();
    void CheckEntityAlive();
    void CheckCollision();
private:
    Player player;
    std::vector<Enemy> enemy;
};
