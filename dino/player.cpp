#include "player.h"

#include "game.h"
#include "world.h"

Player::Player(World& world)
    : WorldObject(world),
      defaultPos_(100, world_.groundLevel()) {

    sf::Vector2f size(30, 30);
    shape_.setSize(size - sf::Vector2f(3, 3));
    shape_.setOutlineThickness(3);
    shape_.setOutlineColor(sf::Color::Yellow);
    shape_.setFillColor(sf::Color(0, 0, 0));
    shape_.setOrigin(size / 2.f);

    shape_.setPosition(defaultPos_);
}

const sf::Drawable& Player::getDrawable() const {
    return shape_;
}

void Player::update(float dt) {
    if (state_ == State::JUMP) {
        double t = jumpClock_.getElapsedTime().asSeconds() * Game::TIME_SCALE;
        double g = 9.8;
        double v_0 = 60;

        double y = world_.groundLevel() - v_0 * t + g * t * t / 2.0;
        shape_.setPosition(defaultPos_.x, y);

        if (shape_.getPosition().y > world_.groundLevel()) {
            state_ = State::RUN;
            shape_.setPosition(defaultPos_);
        }
    }
}


void Player::moveTo(sf::Vector2f pos) {
    shape_.setPosition(pos.x, pos.y);
}

void Player::move(sf::Vector2f delta) {
    shape_.move(delta.x, delta.y);
}

void Player::jump() {
    // disallow double jumps
    if (state_ == State::JUMP)
        return;

    state_ = State::JUMP;
    jumpClock_.restart();
}
