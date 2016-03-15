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

// int i = 0;
// for (auto &laser : Lasers)
// {
//     if (laser.x >= SCREENWIDTH || laser.x <= 0 ||
//         laser.y >= SCREENHEIGHT || laser.y <= 0)
//     {
//         Lasers.erase(Lasers.begin() + i);
//         ++i
//     }
// }