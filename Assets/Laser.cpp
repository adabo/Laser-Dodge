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

void Laser::Update(Laser &Lsr, float Dt) 
{
    float frame_step = 600.0f * Dt;
    Lsr.x += frame_step * Lsr.cos_x;
    Lsr.y += frame_step * Lsr.sin_y;
}

void Laser::Draw(Laser &Lsr, D3DGraphics &Gfx)
{
    Gfx.PutPixel((int)Lsr.x, (int)Lsr.y, 255, 255, 255);
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
