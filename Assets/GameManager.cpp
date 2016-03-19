#include "GameManager.h"

GameManager::GameManager(HWND hWnd, const KeyboardServer& kServer, const MouseServer& mServer)
    :   /*p_lasers(&lasers)*/
        gfx( hWnd ),
        audio( hWnd ),
        kbd( kServer ),
        mouse( mServer )

{
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
