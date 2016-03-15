#include "Physics.h"

void Physics::Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    CollisionCheck(ThisPlayer, Enemies, Lasers);
}

void Physics::CollisionCheck(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                             std::vector<Laser> &Lasers)
{
    // Check player against enemies
    for (auto &enemy : Enemies)
    {
       if ((int)ThisPlayer.GetX() + ThisPlayer.GetWidth() > enemy.GetX() &&
           (int)ThisPlayer.GetX() <(int) enemy.GetX() + enemy.GetWidth() &&
           (int)ThisPlayer.GetY() + ThisPlayer.GetHeight() > (int)enemy.GetY() &&
           (int)ThisPlayer.GetY() < (int)enemy.GetY() + enemy.GetHeight())
       {}
    }
    for (auto &laser : Lasers)
    {
       if ((int)ThisPlayer.GetX() + ThisPlayer.GetWidth() > (int)laser.GetX() &&
           (int)ThisPlayer.GetX() < (int) laser.GetX() + laser.GetWidth() &&
           (int)ThisPlayer.GetY() + ThisPlayer.GetHeight() > (int)laser.GetY() &&
           (int)ThisPlayer.GetY() < (int)laser.GetY() + laser.GetHeight())
       {}
    }
}
