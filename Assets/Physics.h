#include "Player.h"
#include "Enemy.h"
#include "Laser.h"
#include "Entity.h"
#include <vector>

class Physics
{
public:
    void Update(Player &ThisPlayer, std::vector<std::vector<Entity>> &Entities);
    void CollisionCheck(Player &ThisPlayer, std::vector<std::vector<Entity>> &Entities);
};
