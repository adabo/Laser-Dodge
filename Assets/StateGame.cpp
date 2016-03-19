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
            player.Update(kbd, mouse, projectile, lasers, Dt);
            enemy.Update(player, enemies, Dt);
            laser.Update(lasers, Dt);
            physics.Update(*this);
            spawner.Update(*this);
            projectile.Update(lasers);
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