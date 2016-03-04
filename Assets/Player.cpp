#include "Player.h"
#include "Enemy.h"

Player::Player()
    :
    width(80),
    height(80),
    x(10),
    y(10)
{}
Player::~Player() {}

void Player::Shoot()
{}

void Player::SetLaserDirection(int MouseX, int MouseY)
{
    float hypotenuse = 1.0f;
    float cos_x      = 0.0f;
    float sin_y      = 0.0f;

    hypotenuse = trg.GetHypotenuse(x, y, MouseX, MouseY);
    cos_x = trg.GetCosX(x, MouseX, hypotenuse);
    sin_y = trg.GetSinY(y, MouseY, hypotenuse);
    laser.push_back(Laser(10, 10, cos_x, sin_y));
}

void Player::Update(std::vector<Enemy> &enemy,
    KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
{
    int mouse_x, mouse_y;
    float frame_step = speed * Dt;
    if(Mouse.LeftIsPressed())
    {
        if(!mouse_is_pressed)
        {
            mouse_is_pressed = true;
            mouse_x = Mouse.GetMouseX();
            mouse_y = Mouse.GetMouseY();
            // Why do I need Shoot()?
            SetLaserDirection(mouse_x, mouse_y);
        }
    }
    else
    {
        mouse_is_pressed = false;
    }

    if(laser.size() != 0)
    {
        // Temporary use 0 to get global laser speed
        // since all lasers carry same speed
        frame_step = laser[0].speed * Dt;
        int size = laser.size();
        for(int i = 0; i < size; ++i)
        {
            laser[i].x += frame_step * laser[i].cos_x;
            laser[i].y += frame_step * laser[i].sin_y;
        }
    }
    CheckCollision(enemy);
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
    il = 0;
    for (; il < laser.size(); ++il)
    {
        if (laser[il].x <= 0.0f)
        {
            laser.erase(laser.begin() + il);
            --il;
            // --i_laser;
        }
        else if (laser[il].x >= 789.0f)
        {
            laser.erase(laser.begin() + il);
            --il;
            // --i_laser;
        }
        else if (laser[il].y <= 0.0f)
        {
            laser.erase(laser.begin() + il);
            --il;
            // --i_laser;
        }
        else if (laser[il].y >= 589.0f)
        {
            laser.erase(laser.begin() + il);
            --il;
             // --i_laser;
        }
    }
}

void Player::Draw(D3DGraphics &Gfx)
{
    // Maybe create an array of x,y coords before
    // for loop to give small performance boost?
    for (int i = 0; i < laser.size(); ++i)
    {
        Gfx.PutPixel(laser[i].x, laser[i].y, 255, 255, 255);
    }
}

float Player::GetX()
{
    return x;
}

float Player::GetY()
{
    return y;
}
