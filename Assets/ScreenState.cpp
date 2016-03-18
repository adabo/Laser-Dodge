#include "ScreenState.h"

void ScreenState::DrawState(GameManager &Mgr)
{
    switch (Mgr.s_state)
    {
        case GAME:
            DrawGame(Mgr);
        break;
        case GAMEOVER:
            DrawGameOver(Mgr);
        break;
        case GAMEMAINMENU:
            DrawMainMenu(Mgr);
        break;
        case GAMEPAUSE:
            DrawGamePause(Mgr);
        break;
        default:
        break;
    }
}
void ScreenState::DrawMain(GameManager &Mgr)
{
    if (player.is_alive)
    {
        player.Draw(Mgr.gfx);
        enemy.Draw(Mgr.enemies, Mgr.gfx);
        laser.Draw(Mgr.lasers, Mgr.gfx);
    }
    score.Draw(player, Gfx, score.i_score);
}
void ScreenState::DrawGameOver(GameManager &Mgr)
{}
void ScreenState::DrawPause(GameManager &Mgr)
{}
