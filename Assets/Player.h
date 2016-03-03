#pragma once
#include "Enemy.h"
#include "Keyboard.h"
#include "D3DGraphics.h"

class Player
{
public:
    Player();
    ~Player();
    void Shoot();
    void Update(float Enemy_X, float Enemy_Y, KeyboardClient &Kbd);
    void Draw(D3DGraphics &Gfx);
    float GetX();
    float GetY();
private:
    float x, y;
};
