#pragma once
#include <vector>
#include "D3DGraphics.h"
#include "Enemy.h"
#include "Laser.h"

class EntityController
{
public:
    EntityController(D3DGraphics &Gfx,
                     std::vector<Laser> &Lasers,
                     std::vector<Enemy> &Enemies);
    void Update(float Dt);
    void Draw();
private:
    D3DGraphics &gfx;
    std::vector<Laser> &lasers;
    std::vector<Enemy> &enemies;
};