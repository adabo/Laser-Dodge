#pragma once
#include <d3d9.h>
#include "D3DGraphics.h"
#include "Font.h"
#include <stdio.h>

class Score
{
    friend class GameManager;
public:
    Score();
    void Update();
    void Draw(D3DGraphics &Gfx, int Score);
private:
    D3DCOLOR font_surf[512 * 84];
    Font fixedSys;
    char s_score[64];
    int i_score;
};