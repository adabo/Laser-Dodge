#pragma once

class Physics;
class Spawner;

class Entity
{
    friend class Physics;
    friend class Spawner;
public:
    //virtual void Draw(D3DGraphics &Gfx) = 0;
protected:
    float x, y,
          velocity,
          hp,
          damage,
          shield;
    bool  is_alive;
    int   width, height;
};
