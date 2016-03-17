#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Laser.h"
// #include "Entity.h"
#include <vector>

//class GameManager;
enum Side
{
    LEFT, RIGHT, TOP, BOTTOM
};

class Physics
{
public:

    void Update(GameManager &Mgr);
    void CollisionDieByScreen(GameManager &Mgr);
    void CollisionDieByEntity(GameManager &Mgr);
    void CollisionClampToScreen(GameManager &Mgr);
    void ClampThisEntity(Entity &ThisEntity);
    void EntityDieByScreen(Entity &ThisEntity, Player &ThisPlayer, Laser *PLaser = 0);
    bool EntityHitsScreen(Entity &ThisEntity);
    bool EntityClipScreen(Entity &ThisEntity, Side ThisSide);
};
