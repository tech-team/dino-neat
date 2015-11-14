#include "post_pattern.h"

#include "rectangular_obstacle.h"
#include "world.h"

PostPattern::PostPattern(World& world)
    : WorldObject(world, TileType::OBSTACLE),
      ObstaclePattern(world) {
    for (int i = 0; i < 2; ++i) {
        auto obstacle = std::make_shared<RectangularObstacle>(world);
        obstacle->moveTo(sf::Vector2f(world.size().x, world.groundLevel() - i * 30));
        obstacles_.push_back(obstacle);
    }
}

sf::Vector2f PostPattern::getPosition() const {
    return obstacles_[0]->getPosition();
}
