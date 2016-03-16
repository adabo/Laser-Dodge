#include "Enemy.h"

Enemy::Enemy(){}
Enemy::Enemy(int X, int Y, float Cos_X, float Sin_Y, float VelocityIncrease)
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

void Enemy::Update(Player &ThisPlayer, std::vector<Enemy> &Enemies, float Dt)
{
    if(Enemies.size())
    {
        for (auto &enemy : Enemies)
        {
            float frame_step = enemy.velocity * Dt;
            enemy.x += frame_step * enemy.cos_x;
            enemy.y += frame_step * enemy.sin_y;
        }
    }
}

void Enemy::Draw(std::vector<Enemy> &Enemies, D3DGraphics &Gfx)
{
    for (auto &enemy : Enemies)
    {
        Gfx.DrawFilledRect(enemy.x, enemy.y, enemy.x + enemy.width,
                           enemy.y + enemy.height, D3DCOLOR_XRGB(0, 255, 0));
    }
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
