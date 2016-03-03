#pragma once
#include "Laser.h"
#include "Player.h"
#include "Enemy.h"

class Observer
{
public:
    Observer();
    ~Observer();
    void Update(KeyboardClient &Kbd);
    void Draw(D3DGraphics &Gfx);
private:
    Player player;
    Laser laser;
    Enemy enemy;
};
