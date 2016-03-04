#include "Observer.h"

Observer::Observer() {}
Observer::~Observer() {}

void Observer::Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
{
    player.Update(enemy, Kbd, Mouse, Dt);
    int size = enemy.size();
    for(int i_enemy = 0; i_enemy < size; ++i_enemy)
    {
        enemy[i_enemy].Update(player, Dt);
    }
    
}

void Observer::Draw(D3DGraphics &Gfx, MouseClient &Mouse)
{
    player.DrawLaser(Gfx);
    player.DrawPlayer(Gfx, Mouse);
    int size = enemy.size();
    for (int i_enemy = 0; i_enemy < size; ++i_enemy)
    {
        enemy[i_enemy].Draw(Gfx);
    }
}
