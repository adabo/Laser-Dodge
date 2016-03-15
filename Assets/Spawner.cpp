#include "Spawner.h"

void Spawner::Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    // Check if enemies are dead
    CheckIsAlive(ThisPlayer, Enemies, Lasers);
    // Then add them if necessary
    if (Enemies.size() <= 0)
    {
        AddEnemy(ThisPlayer, Enemies);
    }
}

void Spawner::CheckIsAlive(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    // Spawner doesn't care which entity it's
    // checking since the entities will hold
    // their own hp/dmg/shield
    for (int i = Enemies.size() - 1; i >= 0; --i)
    {
        if (Enemies[i].hp <= 0)
        {
            // Enemies[i].is_alive = false;
            Enemies.erase(Enemies.begin() + i);
            AddEnemy(ThisPlayer, Enemies);
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

void Spawner::AddEnemy(Player &ThisPlayer, std::vector<Enemy> &Enemies)
{
    // I should not be hard coding these values especially
    // the height and width. Need to find a more elegant solution
    float x = rand() % (800 - 30 * 2) + 30;
    float y = rand() % (400 - 30 * 2) + 30;

    float hypotenuse = trg.GetHypotenuse(x, y,ThisPlayer.GetX(), ThisPlayer.GetY());
    float cos_x      = trg.GetCosX(x, ThisPlayer.GetX(), hypotenuse);
    float sin_y      = trg.GetSinY(y, ThisPlayer.GetY(), hypotenuse);

    Enemies.push_back(Enemy(x, y, cos_x, sin_y));
}

void Spawner::SetPlayerAlive(Player &ThisPlayer)
{
    if (!ThisPlayer.is_alive)
    {
        ThisPlayer.is_alive = true;
    }
}
