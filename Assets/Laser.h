#pragma once
#include "D3DGraphics.h"
#include <vector>

class Laser
{
public:
    Laser(float X, float Y);
    ~Laser();
    void Shoot();
    void Update(float x, float y);
    void Draw(D3DGraphics &Gfx);
    float GetX();
    float GetY();
public:
    int width, height;
    float speed;
public:
    float x, y;
};
