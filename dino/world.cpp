#include "world.h"

World::World(sf::Vector2f size)
    : size_(size),
      obstacleCreationTimer_(
          sf::seconds(1),
          [this] (Timer& timer) { createObstacle(); }) {

    player_ = std::make_shared<Player>(*this);

    obstacleCreationTimer_.start();
}

void World::draw(sf::RenderWindow& window) const {
    for (const auto& obstacle: obstables_)
        window.draw(obstacle->getDrawable());

    window.draw(player_->getDrawable());
}

void World::update(float dt) {
    for (auto& obstacle: obstables_) {
        obstacle->update(dt);

        obstacle->move(sf::Vector2f(-scrollSpeed_ * dt, 0.f));
    }

    // remove invisible obstacles
    obstables_.erase(std::remove_if(
                         obstables_.begin(),
                         obstables_.end(),
                         [](auto& obstacle) {
        return !obstacle->isVisible();
    }), obstables_.end());

    player_->update(dt);

    // TODO: collision detection

    obstacleCreationTimer_.update();
}

void World::createObstacle() {
    auto obstable = std::make_shared<Obstacle>(*this);
    obstable->moveTo(sf::Vector2f(size_.x, groundLevel_));

    obstables_.emplace_back(obstable);
}

void World::playerJump() {
    player_->jump();
}

double World::groundLevel() const {
    return groundLevel_;
}
