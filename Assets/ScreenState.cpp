#include "ScreenState.h"
#include "GameManager.h"

ScreenState::ScreenState(GameManager &MGR)
:   states(GAMEMAINMENU),
    state_shop(MGR),
    state_game_over(state_game.GetVecText())
{}


void ScreenState::Update(GameManager &Mgr)
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
            Mgr.score_text.Update();
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
        case GAMESHOP:
            state_shop.Update();
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
            Mgr.score_text.Draw();
        break;
        case GAMEOVER:
            state_game_over.Draw(Mgr, Mgr.gfx);
            Mgr.score.Draw(Mgr.player, Mgr.gfx, Mgr.score.targets_hit);
            Mgr.score_text.Draw();
        break;
        case GAMEMAINMENU:
            state_main_menu.Draw(Mgr.gfx);
        break;
        case GAMEPAUSE:
            state_game_pause.Draw(Mgr);
            Mgr.score.Draw(Mgr.player, Mgr.gfx, Mgr.score.targets_hit);
            Mgr.score_text.Draw();
        break;
        case GAMESHOP:
            state_shop.Draw();
        break;
        default:
        break;
    }
}
