#pragma once
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Trigonometry.h"
#include "Score.h"

class Spawner
{
public:
    Spawner();
    void Update(GameManager &Mgr);
    void CheckIsAlive(Player &ThisPlayer, std::vector<Enemy> &Enemies,
                      std::vector<Laser> &Lasers, int &TargsHit);
    void SetPlayerAlive(Player &ThisPlayer);
    void AddEnemy(Player &ThisPlayer, std::vector<Enemy> &Enemies);
    int points; // This is only temporary until class Score or something.
private:

    float speed_increase;
    Trigonometry trg;
};
