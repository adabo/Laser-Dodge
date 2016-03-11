#include "GameManager.h"

void GameManager::SpawnEntity()
{
    enemy.Spawn();
    player.Spawn();
    laser.Spawn();    
}

void GameManager::Update()
{
    // Add entity tpyes here
    
}

void GameManager::Draw()
{}