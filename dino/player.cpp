#include "player.h"

#include "game.h"
#include "obstacle.h"
#include "world.h"
#include "world_rasterizer.h"

Player::Player(World& world)
    : RectangularObject(world, TileType::PLAYER),
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

void Player::jump() {
    // disallow double jumps
    if (state_ == State::JUMP)
        return;

    state_ = State::JUMP;
    jumpClock_.restart();
}

bool Player::passedObstacle(Obstacle& obstacle) const {
    auto bounds = obstacle.shape().getGlobalBounds();

    return shape_.getGlobalBounds().left >
            bounds.left + bounds.width;
}
