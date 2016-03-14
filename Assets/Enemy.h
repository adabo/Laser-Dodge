#pragma once
#include "Laser.h"
#include "D3DGraphics.h"
#include <vector>

class Player;

class Enemy : public Entity
{
public:
    friend Physics;
    Enemy(int X, int Y)
    {
        x        = X;
        y        = Y;
        is_alive = true;
        hp       = 50.0f;
        damage   = 5.0f;
        shield   = 5.0f;
    }
    void Update(Player &Player, float Dt);
    void Deploy();
    void Draw(D3DGraphics &Gfx);
    float GetX();
    float GetY();
};
