#pragma once
#include "Common.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "D3DGraphics.h"
#include <vector>
#include "Laser.h"
#include "Trigonometry.h"

enum AIMSIDE
{
    AIMTOP,
    AIMRIGHT,
    AIMBOTTOM,
    AIMLEFT
};

class Player : public Entity
{
public:
    friend Physics;
    Player();
    void Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt);
    void UpdateLaser(x, y, cos_x, sin_y, float Frame_Step);
    void SetAimDirection(int MouseX, int MouseY);
    void Draw(D3DGraphics &Gfx);
private:
    std::vector<Laser> lasers;
    AIMSIDE aim_side;
    int mouse_x, mouse_y;
    float aim_displacement; 
    Trigonometry trg;
};

