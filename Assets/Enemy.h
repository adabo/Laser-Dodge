#pragma once
#include "Laser.h"
#include "D3DGraphics.h"
#include <vector>
#include "Physics.h"

class Player;

class Enemy : public Entity
{
public:
    Enemy(int X, int Y);
    void Update(Player &Player, float Dt);
    void Deploy();
    void Draw(D3DGraphics &Gfx);
private:
    std::vector<Entity> entities;
};
