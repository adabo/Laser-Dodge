#pragma once
#include "Common.h"

class GameManager;

class ScreenState
{
public:
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr);
    void UpdateGame(GameManager &Mgr);
    void UpdateMainMenu(GameManager &Mgr);
    void UpdateGameOver(GameManager &Mgr);
    void UpdateGamePause(GameManager &Mgr);
    bool YesClicked(int MouseX, int MouseY);
    bool NoClicked();
    bool MouseClickedBox(int MX, int MY, int X, int Y, int W, int H);
private:
    States states;
    int yes_x;
    int yes_y;
    int yes_w;
    int yes_h;
    int no_x;
    int no_y;
    int no_w;
    int no_h;
};