#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include <SFML/Graphics.hpp>


#include "world_rasterizer.h"

class World;
class RectangularObject;

class WorldObject {
public:
    enum class TileType {
        EMPTY, PLAYER, OBSTACLE
    };

    WorldObject(World& world, TileType tile_type = TileType::EMPTY);

    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    virtual void moveTo(sf::Vector2f pos) = 0;
    virtual void move(sf::Vector2f delta) = 0;

    virtual sf::Vector2f getPosition() const = 0;

    virtual void rasterize(PlainWorld& raster, WorldRasterizer& rasterizer) const = 0;

    virtual bool collidesWith(const WorldObject& object) const;
    virtual bool collidesWith(const RectangularObject& object) const;


protected:
    World& world_;
    TileType tile_type_ = TileType::EMPTY;
};

#endif // WORLD_OBJECT_H
