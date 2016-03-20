#pragma once
#include "Common.h"
#include <d3d9.h>
#include "D3DGraphics.h"
#include "Font.h"
#include <stdio.h>
#include "Player.h"

class Score
{
    //friend class ScreenState;
    friend class GameManager;
    friend class Spawner;
    friend class StateGame;
    friend class StateGamePause;
public:
    Score();
    Score(int hp);
    void Update();
    void Draw(Player &ThisPlayer, D3DGraphics &Gfx, int Score);
private:
    int col_r,col_g,col_b;
    D3DCOLOR font_surf[512 * 84];
    Font fixedSys;
    char buffer[64];
    int i_score;
    float dist_pct;
};