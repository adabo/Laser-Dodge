#pragma once
#include <vector>

class Physics;
class Spawner;

class Entity
{
    friend class Physics;
    friend class Spawner;
    friend class GameManager;
    friend class Score;
public:
    //virtual void Draw(D3DGraphics &Gfx) = 0;
    //virtual int GetHeight();
    //virtual int GetWidth();
protected:
    float x, y,
          velocity,
          hp,
          damage,
          shield;
    bool  is_alive;
    int   width, height;
    Entity *p_entity;
};
