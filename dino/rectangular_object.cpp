#include "rectangular_object.h"

#include "world.h"

#include "rectangular_obstacle.h"

RectangularObject::RectangularObject(World& world, WorldObject::TileType tile_type)
    : WorldObject(world, tile_type) {

}

const sf::Drawable& RectangularObject::getDrawable() const {
    return shape_;
}

const sf::RectangleShape& RectangularObject::shape() const {
    return shape_;
}


void RectangularObject::moveTo(sf::Vector2f pos) {
    shape_.setPosition(pos.x, pos.y);
}

void RectangularObject::move(sf::Vector2f delta) {
    shape_.move(delta.x, delta.y);
}

void RectangularObject::rasterize(PlainWorld& raster, WorldRasterizer& rasterizer) const {
    auto pos = shape_.getPosition();
    auto size = shape_.getSize();
    auto scaleFactor = rasterizer.scaleFactor();

    for (int j = pos.y - size.y / 2; j < pos.y + size.y / 2; j += scaleFactor) {
        for (int i = pos.x - size.x / 2; i < pos.x + size.x / 2; i += scaleFactor) {
            if (world_.isPointOnScreen(i, j))
                raster.at(rasterizer.to1d(i, j)) = (int) tile_type_;
        }
    }
}


sf::Vector2f RectangularObject::getPosition() const {
    return shape_.getPosition();
}


bool RectangularObject::collidesWith(const WorldObject& object) const {
    return object.collidesWith(*this);
}

bool RectangularObject::collidesWith(const RectangularObject& object) const {
    return shape_.getGlobalBounds().intersects(
                object.shape_.getGlobalBounds());
}
