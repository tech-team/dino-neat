#include "rectangular_obstacle.h"

#include "world.h"
#include "world_rasterizer.h"

RectangularObstacle::RectangularObstacle(World& world)
    : WorldObject(world, TileType::OBSTACLE),
      Obstacle(world),
      RectangularObject(world, TileType::OBSTACLE) {
    sf::Vector2f size(30, 30);
    shape_.setSize(size - sf::Vector2f(3, 3));
    shape_.setOutlineThickness(3);
    shape_.setOutlineColor(sf::Color::Green);
    shape_.setFillColor(sf::Color(0, 0, 0));
    shape_.setOrigin(size / 2.f);
}


void RectangularObstacle::update(float dt) {

}

bool RectangularObstacle::isVisible() {
    return shape_.getPosition().x > 0;
}
