#pragma once
#include "Font.h"
#include "D3DGraphics.h"
#include "Player.h"
#include "Timer.h"

class GameManager;

class Debug
{
    friend class GameManager;
    friend class StateGame;
    friend class StateGamePause;
public:
    Debug();
    void Update(GameManager &Mgr);
    void Draw(D3DGraphics &Gfx, GameManager &Mgr);
private:
    Timer timer;
    float milli;
    int fps;
    int n_lasers;
    int n_frames;
    bool draw_debug;
    bool tilde_is_pressed;
    // bool tilde_toggle;
    D3DCOLOR font_surf[160 * 29];
    Font edges;
    char buffer[64];
};