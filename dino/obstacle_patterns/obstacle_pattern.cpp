#include "obstacle_pattern.h"

ObstaclePattern::ObstaclePattern(World& world)
    : WorldObject(world, TileType::OBSTACLE) {

}

const sf::Drawable &ObstaclePattern::getDrawable() const {
    throw "Not implemented";
}

void ObstaclePattern::update(float dt) {
    for (auto& obstacle: obstacles_) {
        obstacle->update(dt);
    }
}

void ObstaclePattern::moveTo(sf::Vector2f pos) {
    for (auto& obstacle: obstacles_) {
        obstacle->move(pos - obstacle->shape().getPosition());
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
