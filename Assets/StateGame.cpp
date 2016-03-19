#include "StateGame.h"
#include "GameManager.h"

void StateGame::Update(GameManager &Mgr)
{
    if (!Mgr.player.is_alive)
    {
        states = GAMEOVER;
    }
    else 
    {
        if (Mgr.kbd.SpaceIsPressed())
        {
            states = GAMEPAUSE;
        }
        else
        {
            states = GAME;
            player.Update(Mgr.kbd, Mgr.mouse, Mgr.projectile, Mgr.lasers, Mgr.dt);
            enemy.Update(Mgr.player, Mgr.enemies, Mgr.dt);
            laser.Update(Mgr.lasers, Mgr.dt);
            physics.Update(Mgr);
            spawner.Update(Mgr);
            projectile.Update(Mgr.lasers);
        }
    }
}

void StateGame::Draw(D3DGraphics &Gfx)
{
    Mgr.player.Draw(Mgr.gfx);
    Mgr.enemy.Draw(Mgr.gfx);
    Mgr.laser.Draw(Mgr.gfx);
    Mgr.score.Draw(Mgr.gfx);
}