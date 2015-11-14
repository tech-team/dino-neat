#include "triple_pattern.h"

#include "rectangular_obstacle.h"
#include "world.h"

TriplePattern::TriplePattern(World& world)
    : WorldObject(world, TileType::OBSTACLE),
      ObstaclePattern(world) {
    for (int i = 0; i < 3; ++i) {
        auto obstacle = std::make_shared<RectangularObstacle>(world);
        obstacle->moveTo(sf::Vector2f(world.size().x + i * 30, world.groundLevel()));
        obstacles_.push_back(obstacle);
    }
}

sf::Vector2f TriplePattern::getPosition() const {
    return obstacles_[1]->getPosition();
}
