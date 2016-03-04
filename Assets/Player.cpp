#include "Player.h"
#include "Enemy.h"

Player::Player()
    :
    width(20),
    height(20),
    x(SCREENCENTERX),
    y(SCREENCENTERY),
    mouse_is_pressed(false)
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
    laser.push_back(Laser(x, y, cos_x, sin_y));

    aim_hypotenuse = hypotenuse;
}

void Player::Update(std::vector<Enemy> &enemy,
    KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
{
    // int mouse_x, mouse_y;
    float frame_step = speed * Dt;
    if (Mouse.IsInWindow())
    {
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

void Player::DrawPlayer(D3DGraphics &Gfx, MouseClient &Mouse)
{
     Gfx.DrawRectOutline(SCREENCENTERX - (width / 2), SCREENCENTERY - (height / 2),
                         SCREENCENTERX + (width / 2), SCREENCENTERY + (height / 2),
                         D3DCOLOR_XRGB(255, 255, 255));
     if (Mouse.IsInWindow())
     {
         if (mouse_y <= 291)
         {
            // draw along top edge
            DrawAim(AIMTOP, Mouse.GetMouseX(), Gfx);
         }
         else if (mouse_x >= 308)
         {
            // draw along right edge
            DrawAim(AIMRIGHT, Mouse.GetMouseX(), Gfx);
         }
         else if (mouse_y >= 308)
         {
            // draw along bottom edge
            DrawAim(AIMBOTTOM, Mouse.GetMouseY(), Gfx);
         }
         else if (mouse_x <= 291)
         {
            // draw along left edge
            DrawAim(AIMLEFT, Mouse.GetMouseY(), Gfx);
         }
     }
}

void Player::DrawAim(AIMSIDE AimDir, int MouseDir, D3DGraphics &Gfx)
{
    if (AimDir == AIMTOP)
    { 
         // aim box clip
         //     top
         //  x   y     x   y
         // 391,291 - 408,291 
        if (MouseDir < 391)
        {
            MouseDir = 391;
        }
        if (MouseDir > 408)
        {
            MouseDir = 408;
        }
        Gfx.PutPixel(MouseDir, 291, 255, 0, 0);
        Gfx.PutPixel(MouseDir + 1, 291, 255, 0, 0);
        Gfx.PutPixel(MouseDir, 291 + 1, 255, 0, 0);
        Gfx.PutPixel(MouseDir + 1, 291 + 1, 255, 0, 0);
    }
    else if (AimDir == AIMRIGHT)
    { 
         // aim box clip
         //     right
         //  x   y     x   y
         // 408,291 - 408,308
        if (MouseDir < 291)
        {
            MouseDir = 391;
        }
        if (MouseDir > 308)
        {
            MouseDir = 308;
        }
        Gfx.PutPixel(408, MouseDir, 255, 0, 0);
        Gfx.PutPixel(408 + 1, MouseDir, 255, 0, 0);
        Gfx.PutPixel(408, MouseDir + 1, 255, 0, 0);
        Gfx.PutPixel(408 + 1, MouseDir + 1, 255, 0, 0);
    }
    else if (AimDir == AIMBOTTOM)
    { 
         // aim box clip
         //     bottom
         //  x   y     x   y
         // 408,308 - 391,308
        if (MouseDir < 408)
        {
            MouseDir = 408;
        }
        if (MouseDir > 391)
        {
            MouseDir = 391;
        }
        Gfx.PutPixel(MouseDir, 308, 255, 0, 0);
        Gfx.PutPixel(MouseDir + 1, 308, 255, 0, 0);
        Gfx.PutPixel(MouseDir, 308 + 1, 255, 0, 0);
        Gfx.PutPixel(MouseDir + 1, 308 + 1, 255, 0, 0);
    }
    else if (AimDir == AIMLEFT)
    { 
         // aim box clip
         //     left
         //  x   y     x   y
         // 391,308 - 391,291
        if (MouseDir < 291)
        {
            MouseDir = 291;
        }
        if (MouseDir > 308)
        {
            MouseDir = 308;
        }
        Gfx.PutPixel(391, MouseDir, 255, 0, 0);
        Gfx.PutPixel(391 + 1, MouseDir, 255, 0, 0);
        Gfx.PutPixel(391, MouseDir + 1, 255, 0, 0);
        Gfx.PutPixel(391 + 1, MouseDir + 1, 255, 0, 0);
    }
}

void Player::DrawLaser(D3DGraphics &Gfx)
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
