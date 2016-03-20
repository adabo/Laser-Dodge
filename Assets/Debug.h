#pragma once
#include "Font.h"
#include "D3DGraphics.h"
#include "Player.h"

class Debug
{
    friend class GameManager;
    friend class StateGame;
    friend class StateGamePause;
public:
    Degug();
    void Update();
    void Draw(D3DGraphics &Gfx);
private:
    bool draw_debug;
    bool tilde_is_pressed;    
    D3DCOLOR font_surf[160 * 29];
    Font edges;
    char buffer[64]
};