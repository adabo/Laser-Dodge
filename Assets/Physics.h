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

enum Ty_Entity
{
    PLAYER, ENEMY, LASER
};

class Physics
{
public:

    void Update(GameManager &Mgr);
    void CollisionDieByScreen(GameManager &Mgr);
    void CollisionDieByEntity(GameManager &Mgr);
    void CollisionClampToScreen(GameManager &Mgr);
    void ClampThisEntity(Entity &ThisEntity);
    void EntityDieByScreen(Entity &ThisEntity, Player &ThisPlayer, Ty_Entity Entity_Type);
    bool EntityHitsScreen(Entity &ThisEntity);
    bool EntityClipScreen(Entity &ThisEntity, Side ThisSide);
};
