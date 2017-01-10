#include "Spawner.h"
#include "GameManager.h"

Spawner::Spawner()
:   velocity_increase(0.0f)
{} 

void Spawner::Update(GameManager &Mgr)
{
    // Check if enemies are dead
    CheckIsAlive(Mgr.player, Mgr.enemies, Mgr.lasers, Mgr.score.i_score);
    // Then add them if necessary
    if (Mgr.enemies.size() <= 0)
    {
        AddEnemy(Mgr.player, Mgr.enemies);
    }
}

void Spawner::CheckIsAlive(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers, int &ThisScore)
{
    // Spawner doesn't care which entity it's
    // checking since the entities will hold
    // their own hp/dmg/shield
    for (int i = Enemies.size() - 1; i >= 0; --i)
    {
        if (Enemies[i].hp <= 0 || !Enemies[i].is_alive)
        {
            // This is redundant. Fix this Abel. Seriously :P
            if (Enemies[i].hp <= 0)
            {
                ThisScore += 1;
            }
            Enemies.erase(Enemies.begin() + i);
            AddEnemy(ThisPlayer, Enemies);
        }
    }
    for (int i = Lasers.size() - 1; i >= 0; --i)
    {
        if (Lasers[i].hp <= 0 || !Lasers[i].is_alive)
        {
            Lasers.erase(Lasers.begin() + i);
        }
    }
    if (ThisPlayer.hp <= 0)
    {
        ThisPlayer.is_alive = false;
    }
}

void Spawner::AddEnemy(Player &ThisPlayer, std::vector<Enemy> &Enemies)
{
    velocity_increase += 4.0f;
    // I should not be hard coding these values especially
    // the height and width. Need to find a more elegant solution
    float x = (float)(rand() % (800 - 30 * 2) + 30);
    float y = (float)(rand() % (600 - 30 * 2) + 30);

    float hypotenuse = trg.GetHypotenuse(x, y,ThisPlayer.GetX(), ThisPlayer.GetY());
    float cos_x      = trg.GetCosX(x, ThisPlayer.GetX(), hypotenuse);
    float sin_y      = trg.GetSinY(y, ThisPlayer.GetY(), hypotenuse);

    Enemies.push_back(Enemy(x, y, cos_x, sin_y, velocity_increase));
}

void Spawner::SetPlayerAlive(Player &ThisPlayer)
{
    if (!ThisPlayer.is_alive)
    {
        ThisPlayer.is_alive = true;
    }
}
