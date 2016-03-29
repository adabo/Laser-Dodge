#pragma once
#include "Common.h"
#include <d3d9.h>
#include "D3DGraphics.h"
#include "Font.h"
#include <stdio.h>
#include "Player.h"
#include "ScoreText.h"

class Score
{
    //friend class ScreenState;
    friend class GameManager;
    friend class Spawner;
    friend class ScreenState;
    friend class StateGame;
    friend class StateGamePause;
    friend class ScoreText;
public:
    Score();
    Score(int hp);
    void Update();
    void Draw(Player &ThisPlayer, D3DGraphics &Gfx, int Score);
    int targets_hit;
private:
    int col_r,col_g,col_b;
    D3DCOLOR font_surf[512 * 84];
    Font fixedSys;
    char buffer[64];
    float dist_pct;
};