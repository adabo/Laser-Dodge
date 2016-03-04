#include "Player.h"
#include "Enemy.h"

Player::Player()
    :
    width(80),
    height(80)
{}
Player::~Player() {}

void Player::Shoot()
{

}

void Player::SetLaserDirection(Laser &MyLaser, int MouseX, int MouseY)
{

}

void Player::Update(std::vector<Enemy> &enemy,
    KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
{

    float frame_step = speed * Dt;
    if(Mouse.LeftIsPressed())
    {
        if(!mouse_is_pressed)
        {
            mouse_is_pressed = true;
            laser.push_back( Laser(x, y - 10));
        }
    }
    else
    {
        mouse_is_pressed = false;
    }

    CheckCollision(enemy);
    int size = laser.size();
    for(int i = 0; i < size; ++i)
    {
        laser[i].x += frame_step;
        laser[i].y += frame_step;
    }
}

void Player::CheckCollision(std::vector<Enemy> &enemy)
{
    int ie = 0, il = 0;
    for (std::vector<Enemy>::iterator i_enemy = enemy.begin();
        i_enemy != enemy.end(); ++ie, ++i_enemy)
    {
       for (std::vector<Laser>::iterator i_laser = laser.begin();
            i_laser != laser.end(); ++il, ++i_laser)
       {
           if ((int)i_enemy->GetX() + i_enemy->width > i_enemy->GetX() &&
               (int)i_enemy->GetX() < i_enemy->GetX() + i_enemy->width &&
               i_enemy->GetY() + i_enemy->height > i_enemy->GetY() &&
               i_enemy->GetY() < i_enemy->GetY() + i_enemy->height)
           {
               i_enemy->hp--;
               // Check if enemy hp is 0
               if (i_enemy->hp < 1)
               {
                   // Remove enemy
                   enemy.erase(enemy.begin() + ie);
                   --i_enemy;
                   --ie;
                   // game.score++;
               }
               // Remove laser from memory
               //laser.erase(laser.begin() + il);
               --i_laser;
               --il;
           }
       }
    }
}

void Player::Draw(D3DGraphics &Gfx)
{}

float Player::GetX()
{
    return x;
}

float Player::GetY()
{
    return y;
}
