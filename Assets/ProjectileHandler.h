#pragma once
#include "Laser.h"
#include "Trigonometry.h"

// class GameManager;

class ProjectileHandler
{
public:
    void Update(std::vector<Laser> &Lasers);
    void AddProjectile(std::vector<Laser> &Lasers, float OriginX, float OriginY,
                       float DestinationX, float DestinationY, float Damage);
    void DelProjectile(std::vector<Laser> &Lasers); 
private:
    // std::vector<Laser> lasers;
    Trigonometry trg;
};