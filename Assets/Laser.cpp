#include "Laser.h"

Laser::Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage)
{
    x        = X;
    y        = Y;
    velocity = 900;
    cos_x    = Cos_X;
    sin_y    = Sin_Y;
    is_alive = true;
    damage   = Damage;
}

void Laser::Update(std::vector<Laser> Lasers, float Dt) 
{
    if(lasers.size())
    {
        float frame_step = velocity * Dt;
        for (auto &laser : lasers)
        {
            lasers.x += frame_step * lasers.cos_x;
            lasers.y += frame_step * lasers.sin_y;
        }
    }
}

void Laser::Draw(D3DGraphics &Gfx)
{
    for (auto &laser : lasers)
    {
        Gfx.PutPixel(laser.x, laser.y, 255, 255, 255);
    }
}


