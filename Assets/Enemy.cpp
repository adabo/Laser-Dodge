#include "Enemy.h"

Enemy::Enemy()
    :
    width(30),
    height(30)
{}
Enemy::~Enemy() {}

void Enemy::Shoot()
{}

void Enemy::Update(Player &Player, float Dt)
{}

void Enemy::Draw(D3DGraphics &Gfx)
{}

float Enemy::GetX()
{
    return x;
}

float Enemy::GetY()
{
    return y;
}

// int Enemy::GetHP()const
// {
//     return hp;
// }

//void Enemy::SetHP(int Hp)
//{
//    hp = Hp;
//}
