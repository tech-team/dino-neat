#include "obstacle_pattern.h"

#include <algorithm>
#include <iostream>

ObstaclePattern::ObstaclePattern(World& world)
    : WorldObject(world, TileType::OBSTACLE),
      Obstacle(world) {

}

void ObstaclePattern::update(float dt) {
    for (auto& obstacle: obstacles_) {
        obstacle->update(dt);
    }
}

void ObstaclePattern::draw(sf::RenderWindow& window) {
    for (auto& obstacle: obstacles_) {
        obstacle->draw(window);
    }
}

void ObstaclePattern::moveTo(sf::Vector2f pos) {
    if (obstacles_.size() == 0)
        return;

    sf::Vector2f delta = obstacles_[0]->getPosition() - pos;

    for (auto& obstacle: obstacles_) {
        obstacle->move(delta);
    }
}

void ObstaclePattern::move(sf::Vector2f delta) {
    for (auto& obstacle: obstacles_) {
        obstacle->move(delta);
    }
}

void ObstaclePattern::rasterize(PlainWorld &raster, WorldRasterizer &rasterizer) const {
    for (auto& obstacle: obstacles_) {
        obstacle->rasterize(raster, rasterizer);
    }
}

bool ObstaclePattern::isVisible() {
    return std::any_of(obstacles_.begin(), obstacles_.end(), [] (auto& obstacle) {
        return obstacle->getPosition().x > 0;
    });
}

bool ObstaclePattern::collidesWith(const RectangularObject& object) const {
    return std::any_of(obstacles_.begin(), obstacles_.end(), [&object] (auto& obstacle) {
        return obstacle->collidesWith(object);
    });
}
