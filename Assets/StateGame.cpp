#include "StateGame.h"
#include "GameManager.h"

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
            Mgr.s_state.states = GAMEPAUSE;
        }
        else
        {
            Mgr.s_state.states = GAME;
            Mgr.player.Update(Mgr.kbd, Mgr.mouse, Mgr.projectile, Mgr.lasers, Mgr.dt);
            Mgr.enemy.Update(Mgr.player, Mgr.enemies, Mgr.dt);
            Mgr.laser.Update(Mgr.lasers, Mgr.dt);
            Mgr.physics.Update(Mgr);
            Mgr.spawner.Update(Mgr);
            Mgr.projectile.Update(Mgr.lasers);
        }
    }
}

void StateGame::Draw(GameManager &Mgr)
{
    Mgr.player.Draw(Mgr.gfx);
    Mgr.enemy.Draw(Mgr.enemies,Mgr.gfx);
    Mgr.laser.Draw(Mgr.lasers, Mgr.gfx);
    Mgr.score.Draw(Mgr.player, Mgr.gfx, Mgr.score.i_score);
}