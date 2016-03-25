#include "EntityController.h"

EntityController::EntityController(D3DGraphics &Gfx,
                                   std::vector<Laser> &Lasers,
                                   std::vector<Enemy> &Enemies)
:   gfx(Gfx),
    lasers(Lasers),
    enemies(Enemies)
{}

void EntityController::Update(float Dt)
{
    for (auto &laser: lasers)
    {
        laser.Update(laser, Dt);
    }
    for (auto &enemy: enemies)
    {
        enemy.Update(enemy, Dt);
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