#pragma once
#include "Physics.h"

class Entity
{
    friend Physics;
public:
    virtual void Update(KeyboardClient &Kbd, float Dt) = 0;
    virtual void Update(float Dt) = 0;
    virtual void Draw(D3DGraphics &Gfx) = 0;
protected:
    float x, y,
          velocity,
          hp,
          damage,
          shield;
    bool  is_alive;
    int   width, height;
};
