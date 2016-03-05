#include "Player.h"
#include "Enemy.h"

Player::Player()
    :
    width(20),
    height(20),
    x(SCREENCENTERX),
    y(SCREENCENTERY),
    mouse_is_pressed(false),
    speed(100)
{}
Player::~Player() {}

void Player::Shoot()
{}

void Player::SetLaserDirection(int MouseX, int MouseY)
{
    float hypotenuse = 0.0f;
    float cos_x      = 0.0f;
    float sin_y      = 0.0f;
    float theta      = 0.0f;
    // float run        = 0.0f;
    float rise       = 9.0f;

    hypotenuse = trg.GetHypotenuse(x, y, MouseX, MouseY);
    cos_x = trg.GetCosX(x, MouseX, hypotenuse);
    sin_y = trg.GetSinY(y, MouseY, hypotenuse);
    laser.push_back(Laser(x, y, cos_x, sin_y));
}

void Player::SetAimDirection(int MouseX, int MouseY)
{
    float theta      = 0.0f;
    float adjacent   = 9.0f;
    float opposite   = 9.0f;
    float hypotenuse = 0.0f;
    
    hypotenuse  = trg.GetHypotenuse(x, y, MouseX, MouseY);
    theta       = trg.ThetaFromSin(y - MouseY, hypotenuse);

    // top
    if (theta >= 45 && theta <= 90)
    {
        aim_displacement = trg.AdjacentFromOpposite(opposite, theta);
        aim_side = AIMTOP;
        if (aim_displacement > 10)
            aim_displacement = aim_displacement;
    }
    // right
    else if (theta <= 45 && theta >= -45 && MouseX >= x)
    {
        aim_displacement = trg.OppositeFromAdjacent(adjacent, theta);
        aim_side = AIMRIGHT;
        if (aim_displacement > 10)
            aim_displacement = aim_displacement;
    }
    // bottom
    else if (theta <= -45 && theta >= -90)
    {
        aim_displacement = trg.AdjacentFromOpposite(opposite, theta);
        aim_side = AIMBOTTOM;
        if (aim_displacement > 10)
            aim_displacement = aim_displacement;
    }
    // left
    else if (theta >= -45 && theta <= 45 && MouseY <= x)
    {
        aim_displacement = trg.OppositeFromAdjacent(adjacent, theta);
        aim_side = AIMLEFT;
        if (aim_displacement > 10)
            aim_displacement = aim_displacement;
    }
}

void Player::Update(std::vector<Enemy> &enemy,
    KeyboardClient &Kbd, MouseClient &Mouse, float Dt)
{
    float frame_step = speed * Dt;
    if (Kbd.AIsPressed())
    {
        x -= frame_step;
    }
    if (Kbd.DIsPressed())
    {
        x += frame_step;
    }
    if (Kbd.WIsPressed())
    {
        y -= frame_step;
    }
    if (Kbd.SIsPressed())
    {
        y += frame_step;
    }

    if (Mouse.IsInWindow())
    {
        mouse_x = Mouse.GetMouseX();
        mouse_y = Mouse.GetMouseY();
        SetAimDirection(mouse_x, mouse_y);
        if(Mouse.LeftIsPressed())
        {
            if(!mouse_is_pressed)
            {
                mouse_is_pressed = true;
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
     Gfx.DrawRectOutline(x - (width / 2), y - (height / 2),
                         x + (width / 2), y + (height / 2),
                         D3DCOLOR_XRGB(255, 255, 255));
     if (Mouse.IsInWindow())
     {
/*         mouse_x = Mouse.GetMouseX();
         mouse_y = Mouse.GetMouseY();
         if (mouse_y <= 291)
         {
            // draw along top edge
            DrawAim(AIMTOP, mouse_x, Gfx);
         }
         else if (mouse_x >= 308)
         {
            // draw along right edge
            DrawAim(AIMRIGHT, mouse_x, Gfx);
         }
         else if (mouse_y >= 308)
         {
            // draw along bottom edge
            DrawAim(AIMBOTTOM, mouse_y, Gfx);
         }
         else if (mouse_x <= 291)
         {
            // draw along left edge
            DrawAim(AIMLEFT, mouse_y, Gfx);
         }
*/     
        DrawAim(Gfx);
     }
}

// void Player::DrawAim(AIMSIDE AimDir, int MouseAxis, D3DGraphics &Gfx)
void Player::DrawAim(D3DGraphics &Gfx)
{
/*    if (AimDir == AIMTOP)
    { 
         // aim box clip
         //     top
         //  x   y     x   y
         // 391,291 - 408,291 
        if (MouseAxis < x)
        {
            MouseAxis = x;
        }
        if (MouseAxis > x)
        {
            MouseAxis = x;
        }
        Gfx.PutPixel(MouseAxis, 291, 255, 0, 0);
        Gfx.PutPixel(MouseAxis + 1, 291, 255, 0, 0);
        Gfx.PutPixel(MouseAxis, 291 + 1, 255, 0, 0);
        Gfx.PutPixel(MouseAxis + 1, 291 + 1, 255, 0, 0);
    }
    else if (AimDir == AIMRIGHT)
    { 
         // aim box clip
         //     right
         //  x   y     x   y
         // 408,291 - 408,308
        if (MouseAxis < y)
        {
            MouseAxis = y;
        }
        if (MouseAxis > y)
        {
            MouseAxis = y;
        }
        Gfx.PutPixel(x, MouseAxis, 255, 0, 0);
        Gfx.PutPixel(x + 1, MouseAxis, 255, 0, 0);
        Gfx.PutPixel(x, MouseAxis + 1, 255, 0, 0);
        Gfx.PutPixel(x + 1, MouseAxis + 1, 255, 0, 0);
    }
    else if (AimDir == AIMBOTTOM)
    { 
         // aim box clip
         //     bottom
         //  x   y     x   y
         // 408,308 - 391,308
        if (MouseAxis < x)
        {
            MouseAxis = x;
        }
        if (MouseAxis > x)
        {
            MouseAxis = x;
        }
        Gfx.PutPixel(MouseAxis, y, 255, 0, 0);
        Gfx.PutPixel(MouseAxis + 1, y, 255, 0, 0);
        Gfx.PutPixel(MouseAxis, y + 1, 255, 0, 0);
        Gfx.PutPixel(MouseAxis + 1, y + 1, 255, 0, 0);
    }
    else if (AimDir == AIMLEFT)
    { 
         // aim box clip
         //     left
         //  x   y     x   y
         // 391,308 - 391,291
        if (MouseAxis < y)
        {
            MouseAxis = y;
        }
        if (MouseAxis > y)
        {
            MouseAxis = y;
        }
        Gfx.PutPixel(x + run, y + 9, 255, 0, 0);
        Gfx.PutPixel(x + run + 1, y + 9, 255, 0, 0);
        Gfx.PutPixel(x + run, y + 9 + 1, 255, 0, 0);
        Gfx.PutPixel(x + run + 1, y + 9 + 1, 255, 0, 0);
}*/
        // Gfx.PutPixel(x + aim_displacement, y + 9, 255, 0, 0);
    if (aim_side == AIMTOP)
    {
        Gfx.PutPixel(x + aim_displacement, y + 9, 255, 0, 0);
    }
    else if (aim_side == AIMRIGHT)
    {
        Gfx.PutPixel(x + 8, y + aim_displacement, 255, 0, 0);
    }
    else if (aim_side == AIMBOTTOM)
    {
        Gfx.PutPixel(x + aim_displacement, y + 8, 255, 0, 0);
    }
    else if (aim_side == AIMLEFT)
    {
        Gfx.PutPixel(x + 9, y + aim_displacement, 255, 0, 0);
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
