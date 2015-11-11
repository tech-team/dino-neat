#include "rectangular_obstacle.h"

#include "world.h"
#include "world_rasterizer.h"

RectangularObstacle::RectangularObstacle(World& world)
    : RectangularObject(world, TileType::RectangularObstacle) {
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

void RectangularObstacle::set_passed(bool passed) {
    passed_ = passed;
}

bool RectangularObstacle::is_passed() const {
    return passed_;
}

bool RectangularObstacle::collidesWith(RectangularObstacle& object) {
    // TODO
    return true;
}
