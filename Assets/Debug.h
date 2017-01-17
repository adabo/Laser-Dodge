#pragma once
#include <vector>
#include "Font.h"
#include "D3DGraphics.h"
#include "Player.h"
#include "Timer.h"
#include "Text.h"

class GameManager;

class Debug
{
    friend class GameManager;
    friend class StateGame;
    friend class StateGamePause;
public:
    Debug(GameManager &Mgr);
    void Update(GameManager &Mgr);
    void Draw(D3DGraphics &Gfx, GameManager &Mgr);
private:
    GameManager &mgr;
    Timer timer;
    float milli;
    int fps;
    int n_lasers;
    int n_frames;
    bool draw_debug;
    bool tilde_is_pressed;
    std::vector<Text> debug_text;
    int mouse_x, mouse_y;
};