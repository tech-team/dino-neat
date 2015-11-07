#include "player.h"

Player::Player() {
    sf::Vector2f size(30, 30);
    shape_.setSize(size - sf::Vector2f(3, 3));
    shape_.setOutlineThickness(3);
    shape_.setOutlineColor(sf::Color::Yellow);
    shape_.setFillColor(sf::Color(0, 0, 0));
    shape_.setOrigin(size / 2.f);
}

const sf::Drawable& Player::getDrawable() const {
    return shape_;
}

void Player::update(float dt) {

}


void Player::moveTo(sf::Vector2f pos) {
    shape_.setPosition(pos.x, pos.y);
}

void Player::move(sf::Vector2f delta) {
    shape_.move(delta.x, delta.y);
}
