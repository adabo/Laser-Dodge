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
    for (int i = Enemies.size() - 1; i >= 0; --i)
    {
       if ((int)ThisPlayer.GetX() + ThisPlayer.GetWidth() > Enemies[i].GetX() &&
           (int)ThisPlayer.GetX() <(int) Enemies[i].GetX() + Enemies[i].GetWidth() &&
           (int)ThisPlayer.GetY() + ThisPlayer.GetHeight() > (int)Enemies[i].GetY() &&
           (int)ThisPlayer.GetY() < (int)Enemies[i].GetY() + Enemies[i].GetHeight() ||
           ((int)Enemies[i].x <= 0 || (int)Enemies[i].x >= 798 - Enemies[i].GetWidth() ||
            (int)Enemies[i].y <= 1 || (int)Enemies[i].y >=589 - Enemies[i].GetHeight()))
       {
           Enemies.erase(Enemies.begin() + i);
       }
    }
    // int p = 0;
    //if (Lasers.size() >= 3)
    // for (auto &laser : Lasers)
    if (Lasers.size())
    {
        for (int i = Lasers.size() - 1; i >= 0; --i)
        {
           if ((int)ThisPlayer.GetX() + ThisPlayer.GetWidth() > (int)Lasers[i].GetX() &&
               (int)ThisPlayer.GetX() < (int) Lasers[i].GetX() + Lasers[i].GetWidth() &&
               (int)ThisPlayer.GetY() + ThisPlayer.GetHeight() > (int)Lasers[i].GetY() &&
               (int)ThisPlayer.GetY() < (int)Lasers[i].GetY() + Lasers[i].GetHeight() ||
               (Lasers[i].x <= 1.0f || Lasers[i].x >= 798.0f || Lasers[i].y <= 1.0f || Lasers[i].y >=589.0f))
           {
                // Try adding lasers to erase in array
                // then delete them outside this for loop
               Lasers.erase(Lasers.begin() + i);
           }
        }
    }
}
