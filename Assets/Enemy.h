#pragma once
#include "Entity.h"
// #include "Laser.h"
#include "D3DGraphics.h"
#include <vector>
#include "Player.h"
// #include "Physics.h"
#include "Trigonometry.h"

class Player;

class Enemy : public Entity
{
public:
    Enemy();
    Enemy(int X, int Y, float Cos_X, float Sin_Y);
    void Update(Player &ThisPlayer, std::vector<Enemy> &Enemies, float Dt);
    //void Deploy();
    void Draw(std::vector<Enemy> &Enemy, D3DGraphics &Gfx);
    float GetX();
    float GetY();
    int   GetWidth();
    int   GetHeight();
private:
    float cos_x, sin_y;
    Trigonometry trg;
    std::vector<Enemy> enemies;
};
