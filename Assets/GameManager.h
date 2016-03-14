#pragma once
#include "Player.h"
#include "Physics.h"
#include "Entity.h"
#include "Enemy.h"

class GameManager
{
private:
    GameManager()
    {
        entities.push_back(&player);
        entities.push_back(&enemies);
    }

    void Update(KeyboardClient &Kbd, float Dt)
    {
        player.Update(Kbd, Mouse, Dt);
        physics.Update(entities);
        spawner.Update(entities);
    }

    void Draw()
    {}
private:
    Player player;
    Enemy enemies;
    std::vector<Entity*> entities;
    Physics physics;
    Spawner spawner;
};