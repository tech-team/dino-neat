#include "offsetted_triple_pattern.h"

#include "rectangular_obstacle.h"
#include "world.h"

OffsettedTriplePattern::OffsettedTriplePattern(World& world)
    : WorldObject(world, TileType::OBSTACLE),
      ObstaclePattern(world) {
    for (int i = 0; i < 3; ++i) {
        auto obstacle = std::make_shared<RectangularObstacle>(world);
        obstacle->moveTo(sf::Vector2f(world.size().x + i * 220, world.groundLevel()));
        obstacles_.push_back(obstacle);
    }
}

sf::Vector2f OffsettedTriplePattern::getPosition() const {
    return obstacles_[1]->getPosition();
}
