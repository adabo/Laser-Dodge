#include "GameManager.h"

GameManager::GameManager()
{
    // entities.push_back(player);
    entities.push_back(enemies);
    entities.push_back(lasers);
}
void GameManager::Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
{
    player.Update(Kbd, Mouse, Dt, );
    for (auto &enemy : enemy)
    {
        enemy.Update(player,enemies);
    }
    physics.Update(entities);
    spawner.Update(entities);
    projectile.Update();
}
void GameManager::Draw(D3DGraphics &Gfx)
{}
