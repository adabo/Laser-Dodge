#pragma once
#include "Entity.h"
#include "D3DGraphics.h"
#include "Text.h"
// #include "Trigonometry.h"
// #include "Player.h"

// class Player;

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(float X, float Y, float Cos_X, float Sin_Y, float VelocityIncrease);
    void Update(Enemy &Emy, MouseClient &Mouse, float Dt);
    void Draw(Enemy &Emy, D3DGraphics &Gfx);
    float GetX();
    float GetY();
    int   GetWidth();
    int   GetHeight();
private:
    Text enemy_text;
    float cos_x, sin_y;
};
