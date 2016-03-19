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
    player.Update(kbd, mouse, projectile, lasers, Dt);
    enemy.Update(player, enemies, Dt);
    laser.Update(lasers, Dt);
    physics.Update(*this);
    spawner.Update(*this);
    projectile.Update(lasers);
}
void GameManager::Draw()
{
    s_state.DrawSState(*this);
}
