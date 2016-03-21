#pragma once
#include <stdlib.h>
#include "D3DGraphics.h"
#include "Font.h"

class GameManager;

class StateGameOver
{
public:
    StateGameOver();
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr, D3DGraphics &Gfx);
    void Reset(GameManager &Mgr);
    bool MouseClickedBox(int MX, int MY, int X, int Y, int W, int H);
private:
    D3DCOLOR font_surf[512 * 84];
    Font fixedSys;
    int y_red, y_green, y_blue, n_red, n_green, n_blue;
    int yes_x;
    int yes_y;
    int yes_w;
    int yes_h;
    int no_x;
    int no_y;
    int no_w;
    int no_h;
};