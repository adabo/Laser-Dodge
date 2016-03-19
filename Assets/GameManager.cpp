#include "GameManager.h"

GameManager::GameManager(HWND hWnd, const KeyboardServer& kServer, const MouseServer& mServer)
    :   /*p_lasers(&lasers)*/
        gfx( hWnd ),
        audio( hWnd ),
        kbd( kServer ),
        mouse( mServer ),

{
    srand((unsigned int)time(NULL));
}
void GameManager::Update(float Dt)
{
    dt = Dt;
    ScreenState.Update(*this);
}
void GameManager::Draw()
{
    ScreenState.Draw(*this);
}
