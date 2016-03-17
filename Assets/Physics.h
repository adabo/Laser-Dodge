#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Laser.h"
// #include "Entity.h"
#include <vector>

enum Side
{
    LEFT, RIGHT, TOP, BOTTOM
};

class Physics
{
public:
    void Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                std::vector<Laser> &Lasers);
    void CollisionDieByScreen(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                              std::vector<Laser> &Lasers);
    void CollisionDieByEntity(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                                       std::vector<Laser> &Lasers);
    void CollisionClampToScreen(Entity &ThisEntity);
    void EntityDieByScreen(Player &ThisPlayer, Entity &ThisEntity, Entity *PEntity, Laser *PLaser = 0);
    bool EntityClipScreen(Entity &ThisEntity, Side ThisSide);
    bool EntityHitsScreen(Entity &ThisEntity);
};
