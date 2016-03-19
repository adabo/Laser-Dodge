#pragma once
#include <stdlib.h>

class StateGameOver
{
public:
    StateGameOver();
    void Update();
    void Draw(D3DGraphics &Gfx);
private:
    int yes_x;
    int yes_y;
    int yes_w;
    int yes_h;
    int no_x;
    int no_y;
    int no_w;
    int no_h;
};