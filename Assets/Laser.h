#pragma once
#include "Entity.h"
#include "D3DGraphics.h"
#include "Trigonometry.h"

class Laser : public Entity
{
    friend class ProjectileHandler;
    friend class Physics;
public:
    Laser();
    Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage);
    void Update(Laser &Lsr, float Dt);
    void Draw(Laser &Lsr, D3DGraphics &Gfx);
    // void AddLaser(int MouseX, int MouseY);
    float GetX();
    float GetY();
    int GetWidth();
    int GetHeight();
private:
    float cos_x, sin_y;
    Trigonometry trg;
    Laser *p_laser;
};
