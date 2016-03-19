#pragma once
#include "GameManager.h"

class StateMainMenu
{
public:
    StateMainMenu();
    void Update(GameManager &Mgr);
    void Draw(D3DGraphics &Gfx);
private:
    int laser_dodge_x;
    int laser_dodge_y;
    int laser_dodge_w;
    int laser_dodge_h;
    int play_x;
    int play_y;
    int play_w;
    int play_h;
};