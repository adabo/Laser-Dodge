#pragma once
#include <vector>
#include "Entity.h"
#include "Player.h"

class Spawner
{
public:
    void Update(std::vector<Entity> &Entities);
    void CheckIsAlive(std::vector<Entity> &Entities);
    void SetPlayerAlive(Player &ThisPlayer);
};
