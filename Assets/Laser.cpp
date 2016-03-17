#include "Laser.h"

Laser::Laser(){}
Laser::Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage)
{
    x        = X;
    y        = Y;
    velocity = 600;
    cos_x    = Cos_X;
    sin_y    = Sin_Y;
    is_alive = true;
    damage   = Damage;
    hp       = 1.0f;
    width    = 1;
    height   = 1;
    p_entity = this;
    p_laser = this;
    //velocity = 100;
}

void Laser::Update(std::vector<Laser> &Lasers, float Dt) 
{
    if(Lasers.size())
    {
        float frame_step = 600.0f * Dt;
        for (auto &laser : Lasers)
        {
            laser.x += frame_step * laser.cos_x;
            laser.y += frame_step * laser.sin_y;
        }
    }
}

void Laser::Draw(std::vector<Laser> &Lasers, D3DGraphics &Gfx)
{
    if (Lasers.size() > 10)
    {
        float i = 0;
    }
    for (auto &laser : Lasers)
    {
        Gfx.PutPixel((int)laser.x, (int)laser.y, 255, 255, 255);
    }
}

float Laser::GetX()
{
    return x;
}

float Laser::GetY()
{
    return y; 
}

int Laser::GetWidth()
{
    return width; 
}

int Laser::GetHeight()
{
    return height; 
}
