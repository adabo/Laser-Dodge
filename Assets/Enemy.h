#pragma once
#include "Entity.h"
#include "Laser.h"
#include "D3DGraphics.h"
#include <vector>
#include "Player.h"
#include "Physics.h"

class Player;

class Enemy : public Entity
{
public:
    Enemy(int X, int Y, float Cos_X, float Sin_Y);
    void Update(Entity &ThisEntity, float Dt); 
    void Deploy();
    void Draw(D3DGraphics &Gfx);
private:
    std::vector<Enemy> enemies;
};
