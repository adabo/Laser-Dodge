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

class Enemy;

class Player
{
public:
    Player();
    ~Player();
    void Shoot();
    void SetLaserDirection(int MouseX, int MouseY);
    void Update(std::vector<Enemy> &enemy,
        KeyboardClient &Kbd, MouseClient &Mouse, float Dt);
    void CheckCollision(std::vector<Enemy> &enemy);
    void DrawLaser(D3DGraphics &Gfx);
    void DrawPlayer(D3DGraphics &Gfx, MouseClient &Mouse);
    void DrawAim(AIMSIDE AimDir, int MouseDir, D3DGraphics &Gfx);
    float GetX();
    float GetY();
public:
    int width, height;
    bool mouse_is_pressed;
private:
    int mouse_x, mouse_y;
    float speed;
    float x, y;
    float aim_x, aim_y, aim_hypotenuse;
    std::vector<Laser> laser;
    Trigonometry trg;
};
