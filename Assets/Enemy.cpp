#include "Enemy.h"

Enemy::Enemy(int X, int Y)
{
    x        = X;
    y        = Y;
    is_alive = true;
    hp       = 50.0f;
    damage   = 5.0f;
    shield   = 5.0f;
}

void Enemy::Update(Player &Player, float Dt)
{
    float player_x = Player.GetX();
    float player_y = Player.GetY();
    float rise       = 9.0f;
    float hypotenuse = trg.GetHypotenuse(x, y, player_x, player_y);
    float cos_x      = trg.GetCosX(x, player_x, hypotenuse);
    float sin_y      = trg.GetSinY(y, player_y, hypotenuse);
}

void Enemy::Deploy()
{
    for (int i_enemy = 0; i_enemy < enemy.size(); ++i_enemy)
    {
        if (enemy[i_enemy].is_dead)
        {
            enemy
        }
        x = rand() % (800 - width * 2) + width;
        enemy.push_back(enemy(x, y, cos_x, sin_y));
    }
}

void Enemy::Draw(D3DGraphics &Gfx)
{
    // DrawFilledRect(int Left, int Top, int Right, int Bottom, D3DCOLOR Color)
    x = this->x
    
    DrawFilledRect(x, y, x + width, y + height, D3DCOLOR_XRGB(0, 255, 0));
}

float Enemy::GetX()
{
    return x;
}

float Enemy::GetY()
{
    return y;
}
