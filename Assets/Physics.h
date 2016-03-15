#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Laser.h"
// #include "Entity.h"
#include <vector>

class Physics
{
public:
    void Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                std::vector<Laser> &Lasers);
    void CollisionCheck(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                        std::vector<Laser> &Lasers);
};
