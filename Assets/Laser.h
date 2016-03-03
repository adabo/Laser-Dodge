#pragma once
#include "D3DGraphics.h"
#include <vector>

class Laser
{
public:
    Laser();
    ~Laser();
    void Shoot();
    void Update(float x, float y);
    void Draw(D3DGraphics &Gfx);
    float GetX();
    float GetY();
private:
    float x, y;
};
