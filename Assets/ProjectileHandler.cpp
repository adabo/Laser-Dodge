#include "ProjectHandler.h"

void ProjectileHandler::Update()
{
    DelProjectile();
}

void ProjectHandler::AddProjectile(int X, int Y, float Damage)
{
    float hypotenuse = trg.GetHypotenuse(x, y, MouseX, MouseY);
    float cos_x      = trg.GetCosX(x, MouseX, hypotenuse);
    float sin_y      = trg.GetSinY(y, MouseY, hypotenuse);
    lasers.push_back(Laser(x, y, cos_x, sin_y, Damage));
}

// void ProjectileHandler::CheckIsAlive(std::vector<Laser> &Lasers)
// {
//     for (auto &laser : Lasers)
//     {
//         if (laser.hp <= 0)
//         {
//             laser.is_alive = false;
//         }
//     }
// }

void ProjectileHandler::DelProjectile()
{
    for (auto &laser : Lasers)
    {
        if(!laser.is_alive)
        {
            
        }
    }
}
