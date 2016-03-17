#include "Physics.h"

void Physics::Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    CollisionDieByScreen(ThisPlayer, Enemies, Lasers);
    CollisionDieByEntity(ThisPlayer, Enemies, Lasers);
    CollisionClampToScreen(ThisPlayer);
}

void Physics::CollisionDieByScreen(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    for (auto &enemy : Enemies)
    {
        EntityDieByScreen(ThisPlayer, enemy, &enemy);
    }
    for (auto &laser : Lasers)
    {
        // Pass pointer to laser object to test if the Entity
        // type is Laser and not other inherited Entity. The
        // This test is to log all missed targets from the player
        // and then use to create percentage.
        EntityDieByScreen(ThisPlayer, laser, &laser, laser.p_laser);
    }
    // EntityDieByScreen(ThisPlayer);
}

void Physics::CollisionDieByEntity(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    // Player laser hits enemy
    if (Lasers.size())
    {
        /*Keep this loop until you come up with a solution*/
        /*for player laser and enemy laser.*/
        /*Right now all lasers clip the player. Yes ALL,*/
        /*including the player own laser. That's not good.*/
        for (auto &enemy : Enemies)
        {
            for (int i = Lasers.size() - 1; i >= 0; --i)
            {
                if ((int)Lasers[i].GetX() + Lasers[i].width > (int)enemy.GetX() &&
                   (int)Lasers[i].GetX() < (int) enemy.GetX() + enemy.width &&
                   (int)Lasers[i].GetY() + Lasers[i].height > (int)enemy.GetY() &&
                   (int)Lasers[i].GetY() < (int)enemy.GetY() + enemy.height)
                {
                    enemy.hp -= Lasers[i].damage;
                    Lasers[i].is_alive = false;    
                }
            }
        }
    }

    // Enemy and player collide
    for (int i = Enemies.size() - 1; i >= 0; --i)
    {
        if ((int)ThisPlayer.GetX() + ThisPlayer.width > Enemies[i].GetX() &&
           (int)ThisPlayer.GetX() <(int) Enemies[i].GetX() + Enemies[i].width &&
           (int)ThisPlayer.GetY() + ThisPlayer.height > (int)Enemies[i].GetY() &&
           (int)ThisPlayer.GetY() < (int)Enemies[i].GetY() + Enemies[i].height)
        {
            ThisPlayer.hp -= Enemies[i].damage;
            // Make hp_color a value that is dynamic so that
            // it subtracts evenly no matter what the enemy damage is.
            // 255 / 15(enemy damage) = 17.
            // ThisPlayer.col_r -= ThisPlayer.col_dec;
            ThisPlayer.col_g -= (int)ThisPlayer.col_dec;
            ThisPlayer.col_b -= (int)ThisPlayer.col_dec;
            Enemies[i].is_alive = false;
        }
    }
}

void Physics::CollisionClampToScreen(Entity &ThisEntity)
{
    // Todo: Add enemy laser clamps
    // instead of just dying.
    if (EntityClipScreen(ThisEntity, TOP))
    {
        ThisEntity.y = 1.0f;
    }
    if (EntityClipScreen(ThisEntity, BOTTOM))
    {
        ThisEntity.y = (float)(598 - ThisEntity.height);
    }
    if (EntityClipScreen(ThisEntity, LEFT))
    {
        ThisEntity.x = 1.0f;
    }
    if (EntityClipScreen(ThisEntity, RIGHT))
    {
        ThisEntity.x = (float)(798 - ThisEntity.width);
    }
}

void Physics::EntityDieByScreen(Player &ThisPlayer, Entity &ThisEntity, Entity *PEntity, Laser *PLaser)
{
    if (EntityHitsScreen(ThisEntity))
    {
        if (ThisEntity.p_entity == PEntity)
        {
            /*Player missed targets*/
            ThisPlayer.targets_missed += 1;
        }
        ThisEntity.is_alive = false;
    }
}

bool Physics::EntityHitsScreen(Entity &ThisEntity)
{
    return ((int)ThisEntity.x <= 0 || (int)ThisEntity.x >= 798 - ThisEntity.width ||
            (int)ThisEntity.y <= 1 || (int)ThisEntity.y >= 589 - ThisEntity.height);
}

bool Physics::EntityClipScreen(Entity &ThisEntity, Side ThisSide)
{
    switch(ThisSide)
    {
        case TOP:
            return ((int)ThisEntity.y <= 0);
        break;
        case BOTTOM:
            return ((int)ThisEntity.y > 598 - ThisEntity.width);
        break;
        case LEFT:
            return ((int)ThisEntity.x <= 0);
        break;
        case RIGHT:
            return ((int)ThisEntity.x >= 798 - ThisEntity.height);
        break;
        default:
            return false;
        break;
    }
}