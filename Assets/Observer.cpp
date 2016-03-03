#include "Observer.h"

Observer::Observer() {}
Observer::~Observer() {}

void Observer::Update(KeyboardClient &Kbd)
{
    player.Update(enemy.GetX(), enemy.GetY(), Kbd);
    laser.Update(x, y);
    enemy.Update(player.GetX(), player.GetY());
}

void Observer::Draw(D3DGraphics &Gfx)
{
    player.Draw(Gfx);
    laser.Draw(Gfx);
    enemy.Draw(Gfx);
}
