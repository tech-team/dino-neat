#ifndef RECTANGULAR_OBJECT_H
#define RECTANGULAR_OBJECT_H

#include <SFML/Graphics.hpp>

#include "world_object.h"
class RectangularObstacle;

class WorldRasterizer;

class RectangularObject : virtual public WorldObject {
public:
    RectangularObject(World& world, TileType tile_type = TileType::EMPTY);

    const sf::Drawable& getDrawable() const;
    const sf::RectangleShape& shape() const;

    virtual void draw(sf::RenderWindow& window) override;

    virtual void moveTo(sf::Vector2f pos) override;
    virtual void move(sf::Vector2f delta) override;
    virtual void rasterize(PlainWorld& raster, WorldRasterizer& rasterizer) const override;

    virtual sf::Vector2f getPosition() const override;

    virtual bool collidesWith(const WorldObject& object) const override;
    virtual bool collidesWith(const RectangularObject& object) const override;

protected:
    sf::RectangleShape shape_;
};

#endif // RECTANGULAR_OBJECT_H
