#include "obstacle.h"

#include "world.h"
#include "world_rasterizer.h"

Obstacle::Obstacle(World& world)
    : RectangularObject(world, TileType::Obstacle) {

}

void Obstacle::set_passed(bool passed) {
    passed_ = passed;
}

bool Obstacle::is_passed() const {
    return passed_;
}
