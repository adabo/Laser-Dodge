#pragma once
#include "Laser.h"

class ProjectileHandler
{
public:
    AddProjectile(int X, int Y, float Damage);
private:
    std::vector<Laser> lasers;
};