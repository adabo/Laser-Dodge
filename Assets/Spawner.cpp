#include "Spawner.h"

void Spawner::Update(std::vector<std::vector<Entity>> &Entities)
{
    CheckIsAlive(Entities)
}

// Passing 2 vectors (Enemy, Laser) in one vector
void Spawner::CheckIsAlive(std::vector<std::vector<Entity>> &Entities)
{
    // Spawner doesn't care which entity it's
    // checking since the entities will hold
    // their own hp/dmg/shield
    for (auto &entity : Entities.entities)
    {
        if (entity.hp <= 0)
        {
            entity.is_alive = false;
        }
    }
}

void Spawner::AddEnemy(std::vector<Enemy> &Enemies)
{
    x = rand() % (800 - width * 2) + width;
    Enemies.push_back(enemy(x, y, cos_x, sin_y));
}

void Spawner::SetPlayerAlive(Player &ThisPlayer)
{
    if (!ThisPlayer.is_alive)
    {
        ThisPlayer.is_alive = true;
    }
}
