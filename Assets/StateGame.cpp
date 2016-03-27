#include "StateGame.h"
#include "GameManager.h"

StateGame::StateGame()
:   space_is_pressed(false),
    tab_is_pressed(false)
{}

void StateGame::Update(GameManager &Mgr)
{
    if (!Mgr.player.is_alive)
    {
        Mgr.s_state.states = GAMEOVER;
    }
    else 
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
                Mgr.s_state.states = GAMEPAUSE;
            }
        }

        if (Mgr.kbd.TabIsPressed())
        {
            if (!tab_is_pressed)
            {
                tab_is_pressed = true;
            }
        }
        else
        {
            if (tab_is_pressed)
            {
                tab_is_pressed = false;
                Mgr.s_state.states = GAMESHOP;
            }
          
        }  
        if (Mgr.s_state.states == GAME)
        {
            UpdateAll(Mgr);
        }
    }

}

void StateGame::UpdateAll(GameManager &Mgr)
{
    Mgr.s_state.states = GAME;
    Mgr.debug.Update(Mgr);
    Mgr.player.Update(Mgr.kbd, Mgr.mouse, Mgr.projectile, Mgr.lasers, Mgr.dt);
    Mgr.ec.Update(Mgr.dt);
    Mgr.physics.Update(Mgr);
    Mgr.spawner.Update(Mgr);
    Mgr.projectile.Update(Mgr.lasers);
}

std::vector<Text> StateGame::GetVecText()
{
    return game_text;
}

void StateGame::Draw(GameManager &Mgr)
{
    Mgr.player.Draw(Mgr.gfx);
    Mgr.ec.Draw();
    Mgr.debug.Draw(Mgr.gfx, Mgr);
}
