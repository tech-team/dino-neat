#include "obstacle.h"

Obstacle::Obstacle(World& world)
    : WorldObject(world) {
    sf::Vector2f size(30, 30);
    shape_.setSize(size - sf::Vector2f(3, 3));
    shape_.setOutlineThickness(3);
    shape_.setOutlineColor(sf::Color::Green);
    shape_.setFillColor(sf::Color(0, 0, 0));
    shape_.setOrigin(size / 2.f);
}

const sf::Drawable& Obstacle::getDrawable() const {
    return shape_;
}


void Obstacle::update(float dt) {

}


void Obstacle::moveTo(sf::Vector2f pos) {
    shape_.setPosition(pos.x, pos.y);
}

void Obstacle::move(sf::Vector2f delta) {
    shape_.move(delta.x, delta.y);
}

bool Obstacle::isVisible() {
    return shape_.getPosition().x > 0;
}
