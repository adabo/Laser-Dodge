#pragma once
#include "Common.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "D3DGraphics.h"
#include <vector>
#include "Entity.h"
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
    friend Physics;
public:
    Player();
    void Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt);
    void Update(float Dt) {}
    void SetAimDirection(int MouseX, int MouseY);
    void Draw(D3DGraphics &Gfx);
private:
    std::vector<Laser> lasers;
    AIMSIDE aim_side;
    int mouse_x, mouse_y;
    float aim_displacement; 
    Trigonometry trg;
};

