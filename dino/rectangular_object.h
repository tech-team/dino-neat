#ifndef RECTANGLEOBJECT_H
#define RECTANGLEOBJECT_H

#include <SFML/Graphics.hpp>

#include "world_object.h"
#include "world_rasterizer.h"

class RectangularObject : public WorldObject {
public:
    using WorldObject::WorldObject;

    const sf::Drawable& getDrawable() const;

    virtual void moveTo(sf::Vector2f pos) override;
    virtual void move(sf::Vector2f delta) override;
    virtual void rasterize(PlainWorld& raster, WorldRasterizer& rasterizer) const override;

protected:
    sf::RectangleShape shape_;
};

#endif // RECTANGLEOBJECT_H
