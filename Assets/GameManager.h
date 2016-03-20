#pragma once

#include <time.h>
// #include "Common.h"
#include "ProjectileHandler.h"
#include "Player.h"
#include "Physics.h"
#include "Spawner.h"
#include "Entity.h"
#include "Enemy.h"
#include "Sound.h"
#include "D3DGraphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Score.h"
#include "Debug.h"
#include "ScreenState.h"

class GameManager
{
    friend class Physics;
    friend class ScreenState;
    friend class StateMainMenu;
    friend class StateGameOver;
    friend class StateGame;
    friend class StateGamePause;
    friend class Spawner;
public:
    GameManager(HWND hWnd, D3DGraphics &Gfx, const KeyboardServer& kServer, const MouseServer& mServer);
    void Update(float Dt);
    void Draw();
private:
    DSound         audio;
    D3DGraphics    &gfx;
    KeyboardClient kbd;
    MouseClient    mouse;

    float dt;

    Player             player;
    ProjectileHandler  projectile;
    Enemy              enemy; // Create one object to handle the vector
    std::vector<Enemy> enemies;
    Laser              laser; // Create one object to handle the vector
    std::vector<Laser> lasers;
    Physics            physics;
    Spawner            spawner;
    Score              score;
    Debug              debug;
    ScreenState        s_state;
    // States             states;
};
