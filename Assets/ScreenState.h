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

    StateGame          state_game;
    StateGameOver      state_game_over;
    StateMainMenu      state_main_menu;
    StateGamePause     state_game_pause;
};