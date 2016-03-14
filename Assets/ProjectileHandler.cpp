#include "ProjectHandler.h"

void ProjectHandler::AddProjectile(int X, int Y, float Damage)
{
    float hypotenuse = trg.GetHypotenuse(x, y, MouseX, MouseY);
    float cos_x      = trg.GetCosX(x, MouseX, hypotenuse);
    float sin_y      = trg.GetSinY(y, MouseY, hypotenuse);
    lasers.push_back(Laser(x, y, cos_x, sin_y, Damage));
}
