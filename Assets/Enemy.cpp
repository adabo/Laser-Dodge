#include "Enemy.h"

Enemy::Enemy(){}
Enemy::Enemy(int X, int Y, float Cos_X, float Sin_Y)
{
    x        = X;
    y        = Y;
    cos_x    = Cos_X;
    sin_y    = Sin_Y;
    is_alive = true;
    hp       = 50.0f;
    damage   = 5.0f;
    shield   = 5.0f;
}

void Enemy::Update(Player &ThisPlayer, std::vector<Enemy> &Enemies, float Dt)
{
    float rise; 
    float hypotenuse; 
    for (auto &enemy : Enemies)
    {
        hypotenuse = trg.GetHypotenuse(enemy.x, enemy.y, ThisPlayer.GetX(), ThisPlayer.GetY());
        cos_x      = trg.GetCosX(enemy.x, ThisPlayer.GetX(), hypotenuse);
        sin_y      = trg.GetSinY(enemy.y, ThisPlayer.GetY(), hypotenuse);
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
