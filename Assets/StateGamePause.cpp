#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "StateGamePause.h"
#include "GameManager.h"

StateGamePause::StateGamePause()
:   space_is_pressed(false)
{}

void StateGamePause::Update(GameManager &Mgr)
{
    if (Mgr.kbd.SpaceIsPressed())
    {
        if (!space_is_pressed)
        {
            space_is_pressed = true;
        }
    }
    else
    {
        if (space_is_pressed)
        {
            space_is_pressed = false;
            Mgr.s_state.states = GAME;
        }
    }
}

void StateGamePause::Draw(GameManager &Mgr)
{
    Mgr.s_state.state_game.Draw(Mgr);
}