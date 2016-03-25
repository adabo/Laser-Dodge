#include "StateGame.h"
#include "GameManager.h"

StateGame::StateGame()
:   space_is_pressed(false),
    tab_is_pressed(false),
    game_text({ {"Targets hit:",    16,  504, Text::FIXEDSYS, Text::GREY, Text::GREY},
                {"Targets missed:", 16,  532, Text::FIXEDSYS, Text::GREY, Text::GREY},
                {"Shots missed:",   16,  560, Text::FIXEDSYS, Text::GREY, Text::GREY},
                {"HP:",             624, 560, Text::FIXEDSYS, Text::GREY, Text::GREY}})
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
    for (auto &el : game_text)
    {
        el.Update(Mgr.mouse);
    }
    Mgr.debug.Update(Mgr);
    Mgr.player.Update(Mgr.kbd, Mgr.mouse, Mgr.projectile, Mgr.lasers, Mgr.dt);
    Mgr.ec.Update(Mgr.dt);
    Mgr.physics.Update(Mgr);
    Mgr.spawner.Update(Mgr);
    Mgr.projectile.Update(Mgr.lasers);
}

void StateGame::Draw(GameManager &Mgr)
{
    Mgr.player.Draw(Mgr.gfx);
    Mgr.ec.Draw();
    // Mgr.score.Draw(Mgr.player, Mgr.gfx, Mgr.score.i_score);
    for (auto &el: game_text)
    {
        el.Draw(Mgr.gfx);
    }
    Mgr.debug.Draw(Mgr.gfx, Mgr);
}