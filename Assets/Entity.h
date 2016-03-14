#pragma once
#include "Keyboard.h"
#include "Mouse.h"

class Physics;

class Entity
{
    friend Physics;
public:
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
