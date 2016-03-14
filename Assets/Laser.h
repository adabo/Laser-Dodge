#pragma once
#include "D3DGraphics.h"
#include <vector>

class Laser : public Entity
{
public:
    Laser(float X, float Y, float Cos_X, float Sin_Y, float Damage)
    :   x        (X)
        y        (Y)
        velocity (900)
        cos_x    (Cos_X)
        sin_y    (Sin_Y)
        is_alive (true)
        damage   (Damage)
    {}

    void Update(float Dt)
    {
        if(lasers.size() != 0)
        {
            // Temporary use 0 to get global laser speed
            // since all lasers carry same speed
            frame_step = velocity * Dt;
            for (auto &laser : lasers)
            {
                lasers.x += frame_step * lasers.cos_x;
                lasers.y += frame_step * lasers.sin_y;
            }
        }
    }

    void Draw()
    {
        for (auto &laser : lasers)
        {
            Gfx.PutPixel(laser.x, laser.y, 255, 255, 255);
        }
    }

    void AddLaser(int MouseX, int MouseY)
    {
        float rise       = 9.0f;
        float hypotenuse       = trg.GetHypotenuse(x, y, MouseX, MouseY);
        float cos_x            = trg.GetCosX(x, MouseX, hypotenuse);
        float sin_y            = trg.GetSinY(y, MouseY, hypotenuse);
        laser.push_back(Laser(x, y, cos_x, sin_y));
    }
private:
    float cos_x, sin_y;
    std::vector<Laser> lasers;
};
