#ifndef WORLD_H
#define WORLD_H

#include "player.h"
#include "obstacle.h"

class World {
public:
    World();

private:
    Player player_;
    //cyclic_list<Obstacle> obstables_;
};

#endif // WORLD_H
