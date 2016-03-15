#include "GameManager.h"

GameManager::GameManager()
{
    // entities.push_back(player);
    // entities.push_back(enemies);
    // entities.push_back(lasers);
}
void GameManager::Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
{
    player.Update(Kbd, Mouse, projectile, Dt);
    enemy.Update(player, enemies, Dt);
    laser.Update(lasers, Dt);
    physics.Update(player, enemies, lasers);
    spawner.Update(player, entities, lasers);
    projectile.Update(lasers);
}
void GameManager::Draw(D3DGraphics &Gfx)
{
    player.Draw(Gfx);
    enemy.Draw(enemies, Gfx);
    laser.Draw(lasers, Gfx);
}
