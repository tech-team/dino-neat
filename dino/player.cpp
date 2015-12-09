#include "player.h"

#include "game.h"
#include "obstacle.h"
#include "world.h"
#include "world_rasterizer.h"

constexpr float Player::MAX_JUMP_SPEED;
constexpr float Player::MIN_JUMP_SPEED;

Player::Player(World& world)
    : WorldObject(world, TileType::PLAYER),
      RectangularObject(world, TileType::PLAYER),
      defaultPos_(100, world_.groundLevel()) {

    sf::Vector2f size(15, 30);
    shape_.setSize(size - sf::Vector2f(3, 3));
    shape_.setOutlineThickness(3);
    shape_.setOutlineColor(sf::Color::Yellow);
    shape_.setFillColor(sf::Color(0, 0, 0));
    shape_.setOrigin(size / 2.f);

    shape_.setPosition(defaultPos_);
}

void Player::update(float dt) {
    if (state_ == State::JUMP) {
        double t = jumpClock_.getElapsedTime().asSeconds() * world_.game()->time_scale();
        double g = 9.8;
        double v_0 = initial_jump_speed_;

        double y = world_.groundLevel() - v_0 * t + g * t * t / 2.0;
        shape_.setPosition(defaultPos_.x, y);

        if (shape_.getPosition().y > world_.groundLevel()) {
            state_ = State::RUN;
            shape_.setPosition(defaultPos_);
        }
    }
}

void Player::jumpStart() {
    // disallow double jumps
    if (state_ == State::JUMP)
        return;

    if (state_ != State::JUMP_PREPARE) {
        state_ = State::JUMP_PREPARE;
        jumpClock_.restart();
        jumpEnd();
    }
}

void Player::jumpEnd() {
    if (state_ == State::JUMP_PREPARE) {
        initial_jump_speed_ = std::min(
                    MAX_JUMP_SPEED,
                    jumpClock_.restart().asSeconds() * 200);

        if (initial_jump_speed_ < MIN_JUMP_SPEED)
            initial_jump_speed_ = MIN_JUMP_SPEED;

        state_ = State::JUMP;
    }
}


