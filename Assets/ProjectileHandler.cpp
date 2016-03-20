#include "ProjectileHandler.h"

void ProjectileHandler::Update(std::vector<Laser> &Lasers)
{
    DelProjectile(Lasers);
}

void ProjectileHandler::AddProjectile(std::vector<Laser> &Lasers, float OriginX, float OriginY,
                                      float DestinationX, float DestinationY, float Damage)
{
    float hypotenuse = trg.GetHypotenuse(OriginX, OriginY,DestinationX, DestinationY);
    float cos_x      = trg.GetCosX(OriginX, DestinationX, hypotenuse);
    float sin_y      = trg.GetSinY(OriginY, DestinationY, hypotenuse);
    Lasers.push_back(Laser(OriginX, OriginY, cos_x, sin_y, Damage));
}

void ProjectileHandler::DelProjectile(std::vector<Laser> &Lasers)
{
    for (auto &laser : Lasers)
    {
        if(!laser.is_alive)
        {
            
        }
    }
}
