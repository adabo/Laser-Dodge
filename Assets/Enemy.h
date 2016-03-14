#pragma once
#include "Entity.h"
#include "Laser.h"
#include "D3DGraphics.h"
#include <vector>
#include "Player.h"
#include "Physics.h"
#include "Trigonometry.h"

class Player;

class Enemy : public Entity
{
public:
    Enemy(int X, int Y, float Cos_X, float Sin_Y);
    void Update(Player &ThisPlayer, std::vector<Enemy> &Enemies, float Dt);
    //void Deploy();
    void Draw(D3DGraphics &Gfx);
private:
    float cos_x, sin_y;
    Trigonometry trg;
    std::vector<Enemy> enemies;
};
