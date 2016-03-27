#pragma once
// #include "Font.h"
// #include <stdlib.h>
// #include "D3DGraphics.h"
#include "Text.h"
#include <vector>

class GameManager;

class StateMainMenu
{
public:
    StateMainMenu();
    void Update(GameManager &Mgr);
    void Draw(D3DGraphics &Gfx);
    bool MouseHoverOver(int MX, int MY, int X, int Y, int W, int H);
private:
    std::vector<Text> main_text;
};