#include "GameManager.h"

GameManager::GameManager(HWND hWnd, D3DGraphics &Gfx, const KeyboardServer& kServer, const MouseServer& mServer)
    :   /*p_lasers(&lasers)*/
        //gfx( Gfx ),
        audio( hWnd ),
        kbd( kServer ),
        mouse( mServer ),
        gfx(Gfx),
        player(),
        score((int)player.hp)
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
