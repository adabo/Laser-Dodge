#pragma once
#include "Laser.h"

class ProjectileHandler
{
public:
    void Update();
    void AddProjectile(int X, int Y, float Damage);
    void DelProjectile(); 
private:
    std::vector<Laser> lasers;
};