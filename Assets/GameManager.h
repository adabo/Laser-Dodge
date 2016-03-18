#pragma once

#include <time.h>
#include "Common.h"
#include "ProjectileHandler.h"
#include "Player.h"
#include "Physics.h"
#include "Spawner.h"
#include "Entity.h"
#include "Enemy.h"
#include "D3DGraphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Score.h"
#include "ScreenState.h"

class GameManager
{
    friend class Physics;
    friend class ScreenState;
public:
    GameManager(HWND hWnd, const KeyboardServer& kServer, const MouseServer& mServer);
    void Update();
    void Draw();
private:
    D3DGraphics gfx;
    KeyboardClient kbd;
    MouseClient mouse;
    Player player;
    ProjectileHandler projectile;
    // Create one object to handle the vector
    Enemy enemy;
    std::vector<Enemy> enemies;
    // Create one object to handle the vector
    Laser laser;
    std::vector<Laser> lasers;
    std::vector<Laser> *p_lasers = &lasers;
    std::vector<std::vector<Entity>> entities;
    Physics physics;
    Spawner spawner;
    Score score;
    SState s_state;
};
