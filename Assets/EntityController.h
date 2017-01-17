#pragma once
#include <vector>
#include "D3DGraphics.h"
#include "Mouse.h"
#include "Enemy.h"
#include "Laser.h"

class EntityController
{
public:
    EntityController(D3DGraphics &Gfx, const MouseServer& mServer,
                     std::vector<Laser> &Lasers,
                     std::vector<Enemy> &Enemies);
    void Update(float Dt);
    void Draw();
private:
    // Why do I have to use &gfx if the constructor already has one?
    D3DGraphics &gfx;
    MouseClient mouse;
    std::vector<Laser> &lasers;
    std::vector<Enemy> &enemies;
};