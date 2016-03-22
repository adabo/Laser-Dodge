#pragma once
#include "Common.h"
#include "StateGame.h"
#include "StateGameOver.h"
#include "StateGamePause.h"
#include "StateMainMenu.h"
#include "StateShop.h"

class GameManager;

class ScreenState
{
    friend class StateGame;
    friend class StateGameOver;
    friend class StateGamePause;
    friend class StateMainMenu;
    friend class StateShop;
public:
    ScreenState();
    void Update(GameManager &Mgr);
    void Draw(GameManager &Mgr);
private:
    States states;

    StateGame          state_game;
    StateGameOver      state_game_over;
    StateMainMenu      state_main_menu;
    StateGamePause     state_game_pause;
    StateShop          state_shop;
};