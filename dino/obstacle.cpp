#include "obstacle.h"

#include "world.h"
#include "world_rasterizer.h"

Obstacle::Obstacle(World& world)
    : WorldObject(world, TileType::OBSTACLE) {
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

void Obstacle::rasterize(PlainWorld& raster, WorldRasterizer& rasterizer) const {
    auto pos = shape_.getPosition();
    auto size = shape_.getSize();
    auto scaleFactor = rasterizer.scaleFactor();

    for (int j = pos.y - size.y / 2; j < pos.y + size.y / 2; j += scaleFactor) {
        for (int i = pos.x - size.x / 2; i < pos.x + size.x / 2; i += scaleFactor) {
            raster.at(rasterizer.to1d(i, j)) = (int) tile_type_;
        }
    }
}

bool Obstacle::isVisible() {
    return shape_.getPosition().x > 0;
}
