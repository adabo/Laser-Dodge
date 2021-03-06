#include "Player.h"

Player::Player()
{
    is_alive       = true;
    width          = 20;
    height         = 20;
    x              = 400;
    y              = 300;
    hp             = 300.0f;
    damage         = 15.0f;
    shield         = 1.0f;
    speed          = 100;
    col_dec        = 255 / (hp / 15);
    col_r          = 255;
    col_g          = 255;
    col_b          = 255;
    shots_missed   = 0;
    targets_missed = 0;
    money          = 0;
}

void Player::Update(KeyboardClient &Kbd, MouseClient &Mouse,
                    ProjectileHandler &Projectile, std::vector<Laser> &Lasers, float Dt)
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
                // Does player need to Shoot()?
                Projectile.AddProjectile(Lasers, x + (float)(width / 2), y + (float)(height / 2), (float)mouse_x, (float)mouse_y, damage);
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
    float hypotenuse = trg.GetHypotenuse(x, y, (float)MouseX, (float)MouseY);
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

void Player::SetSpeed(float Speed)
{
    speed = Speed;
}

void Player::Draw(D3DGraphics &Gfx)
{
    Gfx.DrawRectOutline((int)x, (int)y, (int)x + width, (int)y + height, D3DCOLOR_XRGB(col_r, col_g, col_b));
}

void Player::SetX(float X)
{
    x = X;
}

void Player::SetY(float Y)
{
    y = Y;
}

void Player::SetHp(float HP)
{
    hp = HP;
}

void Player::SetDamage(float Dmg)
{
    damage = Dmg;
}

void Player::SetShield(float Shield)
{
    shield = shield;
}

void Player::SetMoney(int Money)
{
    money = Money;
}

float Player::GetX()
{
    return x;
}

float Player::GetY()
{
    return y;
}

int Player::GetWidth()
{
    return width;
}

int Player::GetHeight()
{
    return height;
}
