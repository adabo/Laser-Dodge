#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Enemy.h"

Enemy::Enemy(){}
Enemy::Enemy(float X, float Y, float Cos_X, float Sin_Y, float VelocityIncrease)
:   enemy_text("", 0, 0, Text::EDGES, Text::BLACK, Text::BLACK)
{
    x        = X;
    y        = Y;
    width    = 30;
    height   = 30;
    cos_x    = Cos_X;
    sin_y    = Sin_Y;
    is_alive = true;
    hp       = 50.0f;
    damage   = 15.0f;
    shield   = 5.0f;
    velocity = 100.0f + VelocityIncrease;
}

void Enemy::Update(Enemy &Emy, MouseClient &Mouse, float Dt)
{
    float frame_step = Emy.velocity * Dt;
    Emy.x += frame_step * Emy.cos_x;
    Emy.y += frame_step * Emy.sin_y;
    enemy_text.Update(Mouse);
}

void Enemy::Draw(Enemy &Emy, D3DGraphics &Gfx)
{
    Gfx.DrawFilledRect((int)Emy.x, (int)Emy.y, (int)Emy.x + Emy.width,
                       (int)Emy.y + Emy.height, D3DCOLOR_XRGB(0, 255, 0));
    enemy_text.SetStr(std::to_string(Emy.hp));
    enemy_text.SetX((int)Emy.x);
    enemy_text.SetY((int)Emy.y);
    enemy_text.Draw(Gfx);
}

float Enemy::GetX()
{
    return x;
}

float Enemy::GetY()
{
    return y; 
}

int Enemy::GetWidth()
{
    return width; 
}

int Enemy::GetHeight()
{
    return height; 
}
