#include "world.h"

#include <random>

#include "rectangular_obstacle.h"

class RectangularObstacle;

World::World(sf::Vector2f size)
    : size_(size),
      obstacleCreationTimer_(
          [this] (Timer&) {
              createObstacle();
              obstacleCreationTimer_.startOnce(randomTime(0, 2));
          }) {

    player_ = std::make_shared<Player>(*this);

    obstacleCreationTimer_.startOnce(sf::seconds(0));
}

void World::draw(sf::RenderWindow& window) const {
    for (const auto& obstacle: obstables_)
        window.draw(obstacle->getDrawable());

    window.draw(player_->getDrawable());
}

bool World::update(float dt) {
    for (auto& obstacle: obstables_) {
        obstacle->update(dt);

        obstacle->move(sf::Vector2f(-scrollSpeed_ * dt, 0.f));
    }

    // remove invisible obstacles
    obstables_.erase(std::remove_if(
                         obstables_.begin(),
                         obstables_.end(),
                         [this] (auto& obstacle) {

        return !obstacle->isVisible();
    }), obstables_.end());

    player_->update(dt);

    for (auto& obstacle: obstables_) {
        // collision detection
        if (player_->collidesWith(*obstacle)) {
            return true;
        }

        // jump over detection
        if (!obstacle->is_passed()
                && player_->passedObstacle(*obstacle)) {
            ++score_;
            obstacle->set_passed(true);
        }
    }

    obstacleCreationTimer_.update();

    return false;
}

void World::createObstacle() {
    auto obstable = std::make_shared<RectangularObstacle>(*this);
    obstable->moveTo(sf::Vector2f(size_.x, groundLevel_));

    obstables_.emplace_back(obstable);
}

void World::playerJump() {
    player_->jump();
}

double World::groundLevel() const {
    return groundLevel_;
}

const sf::Vector2f &World::size() const {
    return size_;
}

int World::score() const {
    return score_;
}

bool World::isPointOnScreen(int i, int j) const {
    return i >= 0 && j >= 0 && i < size_.x && j < size_.y;
}

sf::Time World::randomTime(double min, double max) const {
    // seeded random
    static std::mt19937 rand_engine(1234);

    std::uniform_real_distribution<double> unif(min, max);
    return sf::seconds(unif(rand_engine));
}
