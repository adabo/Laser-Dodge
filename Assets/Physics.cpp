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
            ThisPlayer.hp -= Enemies[i].damage;
            // Make hp_color a value that is dynamic so that
            // it subtracts evenly no matter what the enemy damage is.
            // 255 / 15(enemy damage) = 17.
            //ThisPlayer.col_r -= ThisPlayer.col_dec;
            ThisPlayer.col_g -= ThisPlayer.col_dec;
            ThisPlayer.col_b -= ThisPlayer.col_dec;
            Enemies.erase(Enemies.begin() + i);
        }
    }
    if (Lasers.size())
    {
        /*Keep this loop until you come up with a solution*/
        /*for player laser and enemy laser.*/
        /*Right now all lasers clip the player. Yes ALL,*/
        /*including the playser own laser. That's not good.*/

        for (int i = Lasers.size() - 1; i >= 0; --i)
        {
            if /*((int)ThisPlayer.GetX() + ThisPlayer.GetWidth() > (int)Lasers[i].GetX() &&*/
               /*(int)ThisPlayer.GetX() < (int) Lasers[i].GetX() + Lasers[i].GetWidth() &&*/
               /*(int)ThisPlayer.GetY() + ThisPlayer.GetHeight() > (int)Lasers[i].GetY() &&*/
               /*(int)ThisPlayer.GetY() < (int)Lasers[i].GetY() + Lasers[i].GetHeight() ||*/
               (Lasers[i].x <= 1.0f || Lasers[i].x >= 798.0f || Lasers[i].y <= 1.0f || Lasers[i].y >=589.0f)
            {
                // Try adding lasers to erase in array
                // then delete them outside this for loop
               Lasers.erase(Lasers.begin() + i);
            }
        }
        // Need to loop through 2 vectors: Each laser against each enemy.
        for (auto &enemy : Enemies)
        {
            for (int i = Lasers.size() - 1; i >= 0; --i)
            {
                if ((int)Lasers[i].GetX() + Lasers[i].GetWidth() > (int)enemy.GetX() &&
                   (int)Lasers[i].GetX() < (int) enemy.GetX() + enemy.GetWidth() &&
                   (int)Lasers[i].GetY() + Lasers[i].GetHeight() > (int)enemy.GetY() &&
                   (int)Lasers[i].GetY() < (int)enemy.GetY() + enemy.GetHeight())
                {
                    // Try adding lasers to erase in array
                    // then delete them outside this for loop
                    enemy.hp -= Lasers[i].damage;
                    Lasers.erase(Lasers.begin() + i);
                }
            }
        }
    }
}
