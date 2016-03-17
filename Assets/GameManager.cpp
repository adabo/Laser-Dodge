#include "GameManager.h"

GameManager::GameManager()
{
    srand((unsigned int)time(NULL));
    // entities.push_back(player);
    // entities.push_back(enemies);
    // entities.push_back(lasers);
}
void GameManager::Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
{
    if (player.is_alive)
    {
        player.Update(Kbd, Mouse, projectile, lasers, Dt);
    }
    enemy.Update(player, enemies, Dt);
    laser.Update(lasers, Dt);
    physics.Update(player, enemies, lasers);
    spawner.Update(player, enemies, lasers, score.i_score);
    projectile.Update(lasers);
}
void GameManager::Draw(D3DGraphics &Gfx)
{
    if (player.is_alive)
    {
        player.Draw(Gfx);
        enemy.Draw(enemies, Gfx);
        laser.Draw(lasers, Gfx);
    }
    score.Draw(Gfx, score.i_score);
}
