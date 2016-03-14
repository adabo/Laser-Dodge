#include "Physics.h"

void Physics::Update(Player &ThisPlayer, std::vector<std::vector<Entity>> &Entities)
{
    Physics::CollisionCheck(ThisPlayer, Entities);
}

void Physics::CollisionCheck(Player &ThisPlayer, std::vector<std::vector<Entity>> &Entities)
{
    // Check player against enemies
    for (auto &enemies : Entities)
    {
        for (auto &enemy : enemies)
        {
           if ((int)ThisPlayer.x + ThisPlayer.width > enemy.x &&
               (int)ThisPlayer.x <(int) enemy.x + enemy.width &&
               (int)ThisPlayer.y + ThisPlayer.height > (int)enemy.y &&
               (int)ThisPlayer.y < (int)enemy.y + enemy.height)
           {}
        }
    }
}
