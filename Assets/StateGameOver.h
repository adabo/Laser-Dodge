#pragma once
#include "D3DGraphics.h"
#include <vector>
#include "Text.h"
#include "StateGame.h"

class GameManager;

class StateGameOver
{
public:
    StateGameOver(std::vector<Text> &GameText);
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr, D3DGraphics &Gfx);
    void Reset(GameManager &Mgr);
    bool MouseClickedBox(int MX, int MY, int X, int Y, int W, int H);
private:
    std::vector<Text> gameover_text;
    std::vector<Text> game_text;
};