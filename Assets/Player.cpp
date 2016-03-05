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

    if (MouseY > y)
    {
        opposite = -opposite;
        adjacent = -adjacent;
    }
    if (MouseX < x)
    {
        opposite = -opposite;
        adjacent = -adjacent;
    }
    
    hypotenuse  = trg.GetHypotenuse(x, y, MouseX, MouseY);
    theta       = trg.ThetaFromSin(y - MouseY, hypotenuse);

    // top
    if (theta >= 45 && theta <= 90)
    {
        aim_displacement = trg.AdjacentFromOpposite(opposite, theta);
        aim_side = AIMTOP;
    }
    // right
    else if (theta <= 45 && theta >= -45 && MouseX >= x)
    {
        aim_displacement = trg.OppositeFromAdjacent(adjacent, theta);
        if (MouseY > y)
        {
            aim_displacement = -aim_displacement;
        }
        aim_side = AIMRIGHT;
    }
    // bottom
    else if (theta <= -45 && theta >= -90)
    {
        aim_displacement = trg.AdjacentFromOpposite(opposite, theta);
        aim_side = AIMBOTTOM;
    }
    // left
    else if (theta >= -45 && theta <= 45 && MouseY <= x)
    {
        aim_displacement = trg.OppositeFromAdjacent(adjacent, theta);
        if (MouseY > y)
        {
            aim_displacement = -aim_displacement;
        }
        aim_side = AIMLEFT;
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
        }
        else if (laser[il].x >= 789.0f)
        {
            laser.erase(laser.begin() + il);
            --il;
        }
        else if (laser[il].y <= 0.0f)
        {
            laser.erase(laser.begin() + il);
            --il;
        }
        else if (laser[il].y >= 589.0f)
        {
            laser.erase(laser.begin() + il);
            --il;
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
        DrawAim(Gfx);
     }
}

void Player::DrawAim(D3DGraphics &Gfx)
{

    if (aim_side == AIMTOP)
    {
        // Red
        Gfx.PutPixel(x + aim_displacement, y - 9, 255, 100, 100);
        Gfx.PutPixel(x + 1 + aim_displacement, y - 9, 255, 100, 100);
        Gfx.PutPixel(x + aim_displacement, y + 1 - 9, 255, 100, 100);
        Gfx.PutPixel(x + 1 + aim_displacement, y + 1 - 9, 255, 100, 100);
    }
    else if (aim_side == AIMRIGHT)
    {
        // Green
        Gfx.PutPixel(x + 7, y + -aim_displacement, 255, 100, 100);
        Gfx.PutPixel(x + 1 + 7, y + -aim_displacement, 255, 100, 100);
        Gfx.PutPixel(x + 7, y + 1 + -aim_displacement, 255, 100, 100);
        Gfx.PutPixel(x + 1 + 7, y + 1 + -aim_displacement, 255, 100, 100);
    }
    else if (aim_side == AIMBOTTOM)
    {
        // Blue
        Gfx.PutPixel(x + aim_displacement, y + 7, 255, 100, 100);
        Gfx.PutPixel(x + 1 + aim_displacement, y + 7, 255, 100, 100);
        Gfx.PutPixel(x + aim_displacement, y + 1 + 7, 255, 100, 100);
        Gfx.PutPixel(x + 1 + aim_displacement, y + 1 + 7, 255, 100, 100);
    }
    else if (aim_side == AIMLEFT)
    {
        // White
        Gfx.PutPixel(x - 9, y + aim_displacement, 255, 100, 100);
        Gfx.PutPixel(x + 1 - 9, y + aim_displacement, 255, 100, 100);
        Gfx.PutPixel(x - 9, y + 1 + aim_displacement, 255, 100, 100);
        Gfx.PutPixel(x + 1 - 9, y + 1 + aim_displacement, 255, 100, 100);
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
