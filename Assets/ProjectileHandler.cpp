#include "ProjectileHandler.h"

void ProjectileHandler::Update(std::vector<Laser> &Lasers)
{
    DelProjectile(Lasers);
}

void ProjectileHandler::AddProjectile(float OriginX, float OriginY,
                                      float DestinationX, float DestinationY, float Damage)
{
    float hypotenuse = trg.GetHypotenuse(OriginX, OriginY,DestinationX, DestinationY);
    float cos_x      = trg.GetCosX(OriginX, DestinationX, hypotenuse);
    float sin_y      = trg.GetSinY(OriginY, DestinationY, hypotenuse);
    lasers.push_back(Laser(OriginX, OriginY, cos_x, sin_y, Damage));
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

void ProjectileHandler::DelProjectile(std::vector<Laser> &Lasers)
{
    for (auto &laser : Lasers)
    {
        if(!laser.is_alive)
        {
            
        }
    }
}
