#pragma once
#include "D3DGraphics.h"
#include <vector>

class Laser : public Entity
{
public:
    Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage);
    void Update(float Dt);
    void Draw(D3DGraphics &Gfx);
    void AddLaser(int MouseX, int MouseY);
private:
    float cos_x, sin_y;
    std::vector<Laser> lasers;
};
