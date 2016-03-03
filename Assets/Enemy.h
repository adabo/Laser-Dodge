#pragma once
#include "Player.h"
#include "D3DGraphics.h"

class Enemy
{
public:
    Enemy();
    ~Enemy();
    void Shoot();
    void Update(float Player_X, float Player_Y);
    void Draw(D3DGraphics &Gfx);
    float GetX();
    float GetY();
private:
    float x, y;
};