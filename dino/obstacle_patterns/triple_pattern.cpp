#include "triple_pattern.h"

#include "rectangular_obstacle.h"
#include "world.h"

TriplePattern::TriplePattern(World& world)
    : ObstaclePattern(world) {
    for (int i = 0; i < 3; ++i) {
        auto obstacle = std::make_shared<RectangularObstacle>(world);
        obstacle->move(sf::Vector2f(world.size().x + i * 30, world.groundLevel()));
        obstacles_.push_back(obstacle);
    }
}

