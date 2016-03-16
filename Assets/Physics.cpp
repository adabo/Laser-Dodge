#include "Physics.h"

enum Side
{
    LEFT, RIGHT, TOP, BOTTOM
};

void Physics::Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    CollisionDieByScreen(Player, Enemies, Lasers);
    CollisionDieByEntity(Player, Enemies, Lasers);
    CollisionClampToScreen(Player, Enemies, Lasers);
}

void Physics::CollisionDieByScreen(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers)
{
    for (auto &enemy : Enemies)
    {
        EntityDieByScreen(enemy);
    }
    for (auto &laser : Lasers)
    {
        EntityDieByScreen(laser);
    }
    EntityDieByScreen(ThisPlayer);
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

    // Enemy and player collide
    for (int i = Enemies.size() - 1; i >= 0; --i)
    {
        if ((int)ThisPlayer.GetX() + ThisPlayer.GetWidth() > Enemies[i].GetX() &&
           (int)ThisPlayer.GetX() <(int) Enemies[i].GetX() + Enemies[i].GetWidth() &&
           (int)ThisPlayer.GetY() + ThisPlayer.GetHeight() > (int)Enemies[i].GetY() &&
           (int)ThisPlayer.GetY() < (int)Enemies[i].GetY() + Enemies[i].GetHeight())
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
}

void Physics::CollisionClampToScreen()
{
    // Todo: Add enemy laser clamps
    // instead of just dying.
    EntityClipScreen(Player);
}

void Physics::EntityDieByScreen(std::vector<Entity> &ThisEntity)
{
    if (EntityHitsScreen(ThisEntity))
    {
        ThisEntity.is_alive = false;
    }
}

void Physics::EntityClipScreen(Entity &ThisEntity)
{
    if (EntityClipScreen(ThisPlayer, TOP))
    {
        ThisEntity.y = 1;
    }
    if (EntityClipScreen(ThisPlayer, BOTTOM))
    {
        ThisEntity.y = 599 - ThisPlayer.height
    }
    if (EntityClipScreen(ThisPlayer, LEFT))
    {
        ThisEntity.x = 1;
    }
    if (EntityClipScreen(ThisPlayer, RIGHT))
    {
        ThisEntity.x = 799 - ThisPlayer.GetWidth
    }
}

bool Physics::EntityHitsScreen(Entity &ThisEntity)
{
    return ((int)ThisEntity.x <= 0 || (int)ThisEntity.x >= 798 - ThisEntity.GetWidth() ||
            (int)ThisEntity.y <= 1 || (int)ThisEntity.y >= 589 - ThisEntity.GetHeight()));
}

bool Physics::EntityClipScreen(Entity &ThisEntity, Side ThisSide)
{
    switch(ThisSide)
    {
        case TOP:
            return ((int)ThisEntity.x <= 0);
        break;
        case BOTTOM:
            return ((int)ThisEntity.x >= 798 - ThisEntity.GetWidth());
        break;
        case LEFT:
            return ((int)ThisEntity.y <= 1);
        break;
        case RIGHT:
            return ((int)ThisEntity.y >= 589 - ThisEntity.GetHeight());
        break;
    }
}