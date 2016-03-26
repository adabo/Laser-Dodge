#include "EntityController.h"

EntityController::EntityController(D3DGraphics &Gfx, const MouseServer& mServer,
                                   std::vector<Laser> &Lasers,
                                   std::vector<Enemy> &Enemies)
:   gfx(Gfx),
    lasers(Lasers),
    enemies(Enemies),
    mouse(mServer)
{}

void EntityController::Update(float Dt)
{
    for (auto &laser: lasers)
    {
        laser.Update(laser, Dt);
    }
    for (auto &enemy: enemies)
    {
        enemy.Update(enemy, mouse, Dt);
    }
}

void EntityController::Draw()
{
    for (auto &laser: lasers)
    {
        laser.Draw(laser, gfx);
    }
    for (auto &enemy: enemies)
    {
        enemy.Draw(enemy, gfx);
    }
}