#include "Laser.h"

Laser::Laser(float X, float Y)
    :
    width(3),
    height(10)
{
    x = X;
    y = Y;
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
