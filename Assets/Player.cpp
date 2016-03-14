#include "Player.h"

Player::Player()
{
    is_alive = true;
    width    = 20;
    height   = 20;
    x        = 400;
    y        = 300;
    hp       = 50.0f;
    damage   = 1.0f;
    shield   = 1.0f;
}

void Player::Update(KeyboardClient &Kbd, MouseClient &Mouse,
                    ProjectileHandler &Projectile, float Dt)
{
    float frame_step = velocity * Dt;
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
                Projectile.AddProjectile(x, y, mouse_x, mouse_y, damage);
            }
        }
        else
        {
            mouse_is_pressed = false;
        }
    }
}

void Player::SetAimDirection(int MouseX, int MouseY)
{
    float hypotenuse = trg.GetHypotenuse(x, y, MouseX, MouseY);
    float theta      = trg.ThetaFromSin(y - MouseY, hypotenuse);
    float adjacent   = 9.0f;
    float opposite   = 9.0f;

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

    if(theta > 44 && theta < 46)
        theta = theta;
    
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

void Player::Draw(D3DGraphics &Gfx)
{
    Gfx.DrawRectOutline(x - (width / 2), y - (height / 2),
                        x + (width / 2), y + (height / 2),
                        D3DCOLOR_XRGB(255, 255, 255));
    }

