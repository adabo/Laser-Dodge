#pragma once
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Trigonometry.h"

class Spawner
{
public:
    void Update(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                     std::vector<Laser> &Lasers);
    void CheckIsAlive(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                      std::vector<Laser> &Lasers);
    void SetPlayerAlive(Player &ThisPlayer);
    void AddEnemy(Player &ThisPlayer, std::vector<Enemy> &Enemies);
private:
    Trigonometry trg;
};
