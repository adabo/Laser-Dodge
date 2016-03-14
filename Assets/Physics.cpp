#include "Physics.h"

void Physics::Update(std::vector<Entity> &Entities)
{
    CollisionCheck(Entities);
}

void Physics::CollisionCheck(Player &ThisPlayer, Enemy &ThisEnemy, Laser &ThisLaser)
{
    // Check player against enemies
    for (auto &enemy : ThisEnemy.enemies)
    {
       if ((int)ThisPlayer.x + ThisPlayer.width > enemy.x &&
           (int)ThisPlayer.x <(int) enemy.x + enemy.width &&
           (int)ThisPlayer.y + ThisPlayer.height > (int)enemy.y &&
           (int)ThisPlayer.y < (int)enemy.y + enemy.height)
       {}

    }
}
