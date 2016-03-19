#pragma once
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
public:
    Score();
    void Update();
    void Draw(Player &ThisPlayer, D3DGraphics &Gfx, int Score);
private:
    D3DCOLOR font_surf[512 * 84];
    Font fixedSys;
    char buffer[64];
    int i_score;
};