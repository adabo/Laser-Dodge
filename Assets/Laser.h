#pragma once
#include "D3DGraphics.h"
#include <vector>

class Laser
{
public:
    Laser(float X, float Y, float Cos_X, float Sin_Y);
    ~Laser();
    void Shoot();
    void Update(float x, float y);
    void Draw(D3DGraphics &Gfx);
    float GetX();
    float GetY();
public:
    int width, height;
    float speed;
    float rate_of_fire;
public:
    float x, y, cos_x, sin_y;
};
