#pragma once
#include "Laser.h"
#include "Trigonometry.h"

class ProjectileHandler
{
public:
    void Update(std::vector<Laser> &Lasers);
    void AddProjectile(int OriginX, int OriginY,
                       float DestinationX, float DestinationY, float Damage);
    void DelProjectile(); 
private:
    std::vector<Laser> lasers;
    Trigonometry trg;
};