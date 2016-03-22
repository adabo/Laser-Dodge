#pragma once
#include "Font.h"
#include <stdlib.h>
#include "D3DGraphics.h"

class GameManager;

class StateMainMenu
{
public:
    StateMainMenu();
    void Update(GameManager &Mgr);
    void Draw(D3DGraphics &Gfx);
    bool MouseHoverOver(int MX, int MY, int X, int Y, int W, int H);
private:
    D3DCOLOR font_surf[512 * 84];
    Font fixedSys;
    int play_red;
    int play_green;
    int play_blue;
    int laser_dodge_x;
    int laser_dodge_y;
    int laser_dodge_w;
    int laser_dodge_h;
    int play_x;
    int play_y;
    int play_w;
    int play_h;
};