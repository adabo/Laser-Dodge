#include "ScreenState.h"
#include "GameManager.h"


void ScreenState::Update(GameManager &Mgr, float Dt)
{

    // During each state it will set the next state
    // the game should be in. ie:
    // if game is active and player pauses the game
    // then game sets states = GAMEPAUSE
    // If the game is paused and the player unpauses
    // then the gamepuase stat will set states = GAME
    switch (states)
    {
        case GAME:
            state_game.Update(Mgr);
        break;
        case GAMEOVER:
            state_game_over.Update(Mgr);
        break;
        case GAMEMAINMENU:
            state_main_menu.Update(Mgr);
        break;
        case GAMEPAUSE:
            state_game_pause.Update(Mgr);
        break;
        default:
        break;
    }
}

void ScreenState::Draw(GameManager &Mgr)
{
    switch (states)
    {
        case GAME:
            state_game.Draw(Mgr);
        break;
        case GAMEOVER:
            state_game_over.Draw(Mgr);
        break;
        case GAMEMAINMENU:
            state_main_menu.Draw(Mgr);
        break;
        case GAMEPAUSE:
            state_game_pause.Draw(Mgr);
        break;
        default:
        break;
    }
}

void ScreenState::UpdateMainMenu(GameManager &Mgr)
{
}

void ScreenState::ScreenState::UpdateGamePause(GameManager &Mgr)
{}