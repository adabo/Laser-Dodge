#include "Enemy.h"

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
void Enemy::Update(Entity &ThisEntity, float Dt)
{
    float rise; 
    float hypotenuse; 
    for (auto &enemy : ThisEnemy.enemies)
    {
        x          = ThisPlayer.x;
        y          = ThisPlayer.y;
        // rise    = 9.0f;
        hypotenuse = trg.GetHypotenuse(x, y, enemy_x, enemy_y);
        cos_x      = trg.GetCosX(x, enemy_x, hypotenuse);
        sin_y      = trg.GetSinY(y, enemy_y, hypotenuse);
    }
}

void Enemy::Deploy()
{
    x = rand() % (800 - width * 2) + width;
    enemies.push_back(enemy(x, y, cos_x, sin_y));
}

void Enemy::Draw(D3DGraphics &Gfx)
{
    // DrawFilledRect(int Left, int Top, int Right, int Bottom, D3DCOLOR Color)
    // x = this->x
    Gfx.DrawFilledRect(x, y, x + width, y + height, D3DCOLOR_XRGB(0, 255, 0));
}
