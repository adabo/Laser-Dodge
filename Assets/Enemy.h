#pragma once
#include "Entity.h"
#include "D3DGraphics.h"
#include <vector>
#include "Player.h"
#include "Trigonometry.h"
#include "Font.h"

class Player;

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(float X, float Y, float Cos_X, float Sin_Y, float VelocityIncrease);
    void Update(Enemy &Emy, float Dt);
    void Draw(Enemy &Emy, D3DGraphics &Gfx);
    float GetX();
    float GetY();
    int   GetWidth();
    int   GetHeight();
private:
    float cos_x, sin_y;
    Trigonometry trg;
    D3DCOLOR font_surf[160 * 29];
    Font edges;
    char buffer[64];
};
