#include "Laser.h"

Laser::Laser(float X, float Y, float Cos_X, float Sin_Y)
    :
    width(3),
    height(10),
    speed(900.0f)
{
    x = X;
    y = Y;
    cos_x = Cos_X;
    sin_y = Sin_Y;
}

Laser::~Laser() {}

void Laser::Shoot()
{}

void Laser::Update(float x, float y)
{}

void Laser::Draw(D3DGraphics &Gfx)
{}

float Laser::GetX()
{
    return x;
}

float Laser::GetY()
{
    return y;
}
