#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <SFML/Graphics.hpp>

#include "world_rasterizer.h"

class World;

class WorldObject {
public:
    enum class TileType {
        EMPTY, PLAYER, OBSTACLE
    };

    WorldObject(World& world, TileType tile_type = TileType::EMPTY);

    virtual const sf::Drawable& getDrawable() const = 0;
    virtual void update(float dt) = 0;

    virtual void moveTo(sf::Vector2f pos) = 0;
    virtual void move(sf::Vector2f delta) = 0;

    virtual void rasterize(PlainWorld& raster, WorldRasterizer& rasterizer) const = 0;

    virtual void collidesWith(WorldObject& world_object) = 0;

protected:
    World& world_;
    TileType tile_type_ = TileType::EMPTY;
};

#endif // WORLDOBJECT_H
