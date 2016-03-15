#pragma once
#include <vector>
#include "Entity.h"
#include "Player.h"

class Spawner
{
public:
    void Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers);
    void CheckIsAlive(std::vector<std::vector<Entity>> &Entities);
    void SetPlayerAlive(Player &ThisPlayer);
    void AddEnemy(std::vector<Enemy> &Enemies);
};
