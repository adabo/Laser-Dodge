#include "Physics.h"
#include "GameManager.h"

void Physics::Update(GameManager &Mgr)
{
    CollisionDieByScreen(Mgr);
    CollisionDieByEntity(Mgr);
    CollisionClampToScreen(Mgr);
}
void Physics::CollisionDieByScreen(GameManager &Mgr)
{
    for (auto &enemy : Mgr.enemies)
    {
        EntityDieByScreen(enemy, Mgr.player, ENEMY);
    }
    for (auto &laser : Mgr.lasers)
    {
        // Pass pointer to laser object to test if the Entity
        // type is Laser and not other inherited Entity. The
        // This test is to log all missed targets from the player
        // and then use to create percentage.
        EntityDieByScreen(laser, Mgr.player, LASER);
    }
    // EntityDieByScreen(ThisPlayer);
}
void Physics::CollisionDieByEntity(GameManager &Mgr)
{
    // Player laser hits enemy
    if (Mgr.lasers.size())
    {
        /*Keep this loop until you come up with a solution*/
        /*for player laser and enemy laser.*/
        /*Right now all lasers clip the player. Yes ALL,*/
        /*including the player own laser. That's not good.*/
        for (auto &enemy : Mgr.enemies)
        {
            for (int i = Mgr.lasers.size() - 1; i >= 0; --i)
            {
                if ((int)Mgr.lasers[i].GetX() + Mgr.lasers[i].width > (int)enemy.GetX() &&
                   (int)Mgr.lasers[i].GetX() < (int) enemy.GetX() + enemy.width &&
                   (int)Mgr.lasers[i].GetY() + Mgr.lasers[i].height > (int)enemy.GetY() &&
                   (int)Mgr.lasers[i].GetY() < (int)enemy.GetY() + enemy.height)
                {
                    enemy.hp -= Mgr.lasers[i].damage;
                    Mgr.lasers[i].is_alive = false;    
                }
            }
        }
    }

    // Enemy and player collide
    for (int i = Mgr.enemies.size() - 1; i >= 0; --i)
    {
        if ((int)Mgr.player.GetX() + Mgr.player.width > Mgr.enemies[i].GetX() &&
           (int)Mgr.player.GetX() <(int) Mgr.enemies[i].GetX() + Mgr.enemies[i].width &&
           (int)Mgr.player.GetY() + Mgr.player.height > (int)Mgr.enemies[i].GetY() &&
           (int)Mgr.player.GetY() < (int)Mgr.enemies[i].GetY() + Mgr.enemies[i].height)
        {
            Mgr.player.hp -= Mgr.enemies[i].damage;
            // Make hp_color a value that is dynamic so that
            // it subtracts evenly no matter what the enemy damage is.
            // 255 / 15(enemy damage) = 17.
            // ThisPlayer.col_r -= ThisPlayer.col_dec;
            Mgr.player.col_g -= (int)Mgr.player.col_dec;
            Mgr.player.col_b -= (int)Mgr.player.col_dec;
            Mgr.enemies[i].is_alive = false;
        }
    }
}
void Physics::CollisionClampToScreen(GameManager &Mgr)
{
    // Todo: Add enemy laser clamps
    for (auto &enemy : Mgr.enemies)
    {
        ClampThisEntity(enemy);
    }
    for (auto &laser : Mgr.lasers)
    {
        ClampThisEntity(laser);
    }
    ClampThisEntity(Mgr.player);
}
void Physics::ClampThisEntity(Entity &ThisEntity)
{
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
void Physics::EntityDieByScreen(Entity &ThisEntity, Player &ThisPlayer, Ty_Entity Entity_Type)
{
    if (EntityHitsScreen(ThisEntity))
    {

        if (Entity_Type == LASER)
        {
            /*Player missed targets*/
            ThisPlayer.shots_missed += 1;
        }
        if (Entity_Type == ENEMY)
        {
            /*Player lost target*/
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
