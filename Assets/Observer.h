#pragma once
#include "Laser.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Observer
{
public:
    Observer();
    ~Observer();
    void Update(KeyboardClient &Kbd, MouseClient &Mouse, float Dt);
    void Draw(D3DGraphics &Gfx, MouseClient &Mouse);
private:
    Player player;
    std::vector<Enemy> enemy;
};
