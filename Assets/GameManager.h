#pragma once
#include <time.h>
#include "ProjectileHandler.h"
#include "Player.h"
#include "Physics.h"
#include "Spawner.h"
#include "Entity.h"
#include "Enemy.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "D3DGraphics.h"
#include "Score.h"

class GameManager
{
public:
    GameManager();
    void Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt);
    void Draw(D3DGraphics &Gfx);
private:
    Player player;
    ProjectileHandler projectile;
    Enemy enemy;
    std::vector<Enemy> enemies;
    Laser laser;
    std::vector<Laser> lasers;
    std::vector<std::vector<Entity>> entities;
    Physics physics;
    Spawner spawner;
    Score score;
};
