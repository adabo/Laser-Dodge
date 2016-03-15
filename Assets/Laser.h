#pragma once
#include "Entity.h"
#include "D3DGraphics.h"
#include "Trigonometry.h"
#include <vector>

class Laser : public Entity
{
    friend class ProjectileHandler;
public:
    Laser();
    Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage);
    void Update(std::vector<Laser> Lasers, float Dt);
    void Draw(std::vector<Laser> &Lasers, D3DGraphics &Gfx);
    // void AddLaser(int MouseX, int MouseY);
    float GetX();
    float GetY();
    int GetWidth();
    int GetHeight();
private:
    float cos_x, sin_y;
    Trigonometry trg;
};
