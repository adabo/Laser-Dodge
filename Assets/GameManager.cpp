#include "GameManager.h"

GameManager::GameManager()
{
    entities.push_back(&player);
    entities.push_back(&enemies);
}
void GameManager::Update(KeyboardClient &Kbd, float Dt)
{
    player.Update(Kbd, Mouse, Dt);
    physics.Update(entities);
    spawner.Update(entities);
}
void GameManager::Draw()
{}
