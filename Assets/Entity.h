#pragma once
#include <vector>
#include "D3DGraphics.h"

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
    virtual void Update(Entity Ent, float Dt);
    virtual void Draw(Entity Ent, D3DGraphics Gfx);
protected:
    float x, y,
          speed,
          hp,
          damage,
          shield;
    bool  is_alive;
    int   width, height;
    Entity *p_entity;
};
