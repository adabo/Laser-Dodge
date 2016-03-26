#include "GameManager.h"

GameManager::GameManager(HWND hWnd, D3DGraphics &Gfx, const KeyboardServer& kServer, const MouseServer& mServer)
    :   audio( hWnd ),
        kbd( kServer ),
        mouse( mServer ),
        gfx(Gfx),
        player(),
        s_state(*this),
        score((int)player.hp),
        ec(Gfx, mServer, lasers, enemies)
{
    //score = Score(player.hp);
    srand((unsigned int)time(NULL));
}

void GameManager::Update(float Dt)
{
    dt = Dt;
    s_state.Update(*this);
}

void GameManager::Draw()
{
    s_state.Draw(*this);
}
