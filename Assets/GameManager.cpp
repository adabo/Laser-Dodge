#include "GameManager.h"

GameManager::GameManager(HWND hWnd, D3DGraphics &Gfx, const KeyboardServer& kServer, const MouseServer& mServer)
    :   audio( hWnd ),
        kbd( kServer ),
        mouse( mServer ),
        gfx(Gfx),
        player(),
        score((int)player.hp),
        ec(Gfx, mServer, lasers, enemies),
        score_text(*this),
        s_state(*this),
        debug(*this)
{
    //score = Score(player.hp);
    srand((unsigned int)time(NULL));
}

void GameManager::Update(float Dt)
{
    if (score.targets_hit > 0)
        score.targets_hit = score.targets_hit;
    dt = Dt;
    s_state.Update(*this);
}

void GameManager::Draw()
{
    s_state.Draw(*this);
}
