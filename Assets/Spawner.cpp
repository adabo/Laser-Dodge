#include "Spawner.h"

void Spawner::Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    CheckIsAlive(Player, Enemies, Lasers)
}

void Spawner::CheckIsAlive(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    // Spawner doesn't care which entity it's
    // checking since the entities will hold
    // their own hp/dmg/shield
    for (auto &enemy : Enemies)
    {
        if (enemy.hp <= 0)
        {
            enemy.is_alive = false;
        }
    }
    for (auto &laser : Lasers)
    {
        if (laser.hp <= 0)
        {
            laser.is_alive = false;
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
