#include "vertical_triple_pattern.h"

#include "rectangular_obstacle.h"
#include "world.h"

VerticalTriplePattern::VerticalTriplePattern(World& world)
    : WorldObject(world, TileType::OBSTACLE),
      ObstaclePattern(world) {
    for (int i = 0; i < 3; ++i) {
        auto obstacle = std::make_shared<RectangularObstacle>(world);
        obstacle->moveTo(sf::Vector2f(world.size().x, world.groundLevel() - i * 30));
        obstacles_.push_back(obstacle);
    }
}

sf::Vector2f VerticalTriplePattern::getPosition() const {
    return obstacles_[1]->getPosition();
}
