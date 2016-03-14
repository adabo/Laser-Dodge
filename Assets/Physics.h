#include "Player.h"
#include "Entity.h"

class Physics
{
public:
    void Update(std::vector<Entity> &Entities);
    void CollisionCheck(Player &ThisPlayer, std::vector<Entity> Enemies);
};
