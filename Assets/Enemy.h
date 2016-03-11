#pragma once
#include "Laser.h"
#include "D3DGraphics.h"
#include <vector>

class Player;

class Enemy
{
public:
    Enemy();
    ~Enemy();
    void Shoot();
    void Update(Player &Player, float Dt);
    void Draw(D3DGraphics &Gfx);
    // int GetHP()const;
    float GetX();
    float GetY();
    bool  GetIsAlive();
    
public:
    void SetCollision();
    void SetEntityCollision();
    void SetObjectCollision();
    void SetScreenCollision();
    void Get
    //void SetHP(int Hp);
public:
    int width, height;
    int hp;
private:
    float speed;
    float x, y;
    std::vector<Laser> laser;
};