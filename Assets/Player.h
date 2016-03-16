#pragma once
#include "ProjectileHandler.h"
#include "Common.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "D3DGraphics.h"
// #include <vector>
#include "Entity.h"
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
    friend Physics;
public:
    Player();
    void Update(KeyboardClient &Kbd, MouseClient &Mouse,
                    ProjectileHandler &Projectile, std::vector<Laser> &Lasers, float Dt);
    void SetAimDirection(int MouseX, int MouseY);
    void Draw(D3DGraphics &Gfx);
    float GetX();
    float GetY();
    int   GetWidth();
    int   GetHeight();
private:
    float col_dec;
    int col_r;
    int col_g;
    int col_b;
    bool mouse_is_pressed;
    ProjectileHandler projectile;
    AIMSIDE aim_side;
    int mouse_x, mouse_y;
    float aim_displacement; 
    Trigonometry trg;
};
