#ifndef WORLD_H
#define WORLD_H

#include <deque>

#include "obstacle.h"
#include "player.h"

class World {
public:
    World();

private:
    Player player_;
    std::deque<Obstacle> obstables_;
};

#endif // WORLD_H
