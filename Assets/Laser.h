#pragma once
#include "Entity.h"
#include "D3DGraphics.h"
#include "Trigonometry.h"
#include <vector>

class Laser : public Entity
{
public:
    Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage);
    void Update(std::vector<Laser> Lasers, float Dt);
    void Draw(D3DGraphics &Gfx) override;
    void AddLaser(int MouseX, int MouseY);
private:
    float cos_x, sin_y;
    Trigonometry trg;
};
