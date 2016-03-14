#include "Spawner.h"

void Spawner::Update(std::vector<Entity> &Entities)
{
    CheckIsAlive(Entities)
}

void Spawner::CheckIsAlive(std::vector<Entity> &Entities)
{
    // Spawner doesn't care which entity it's
    // checking since the entities will hold
    // their own hp/dmg/shield
    for (auto &entity : Entities)
    {
        if (entity.hp <= 0)
        {
            entity.is_alive = false;
        }
    }
}

void Spawner::SetPlayerAlive(Player &ThisPlayer)
{
    if (!ThisPlayer.is_alive)
    {
        ThisPlayer.is_alive = true;
    }
}
