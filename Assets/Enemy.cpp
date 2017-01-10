#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Enemy.h"

Enemy::Enemy(){}
Enemy::Enemy(float X, float Y, float Cos_X, float Sin_Y, float VelocityIncrease)
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
    edges.LoadFont(&edges, font_surf, "Edges_5x10x32.bmp", 5, 10, 32);
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
        Gfx.DrawFilledRect((int)enemy.x, (int)enemy.y, (int)enemy.x + enemy.width,
                           (int)enemy.y + enemy.height, D3DCOLOR_XRGB(0, 255, 0));
        sprintf(buffer, "%.2f", enemy.hp);
        // Because it's a vector you must add enemy. in front of the edges font
        // otherwise just using 'edges' with 'enemy.' means you are using the
        // Mgr.enemy.edges which was never constructed with the font.Load()
        enemy.edges.DrawString(buffer, (int)enemy.x + 4, (int)enemy.y + (enemy.height / 2),
                         &enemy.edges, D3DCOLOR_XRGB(0, 0, 0), Gfx);
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
