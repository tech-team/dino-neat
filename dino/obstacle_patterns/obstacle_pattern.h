#ifndef OBSTACLE_PATTERN_H
#define OBSTACLE_PATTERN_H

#include <memory>
#include <vector>

#include "obstacle.h"

class ObstaclePattern : public WorldObject {
public:
    ObstaclePattern(World &world);

    virtual const sf::Drawable &getDrawable() const override;
    virtual void update(float dt) override;
    virtual void moveTo(sf::Vector2f pos) override;
    virtual void move(sf::Vector2f delta) override;
    virtual void rasterize(PlainWorld &raster, WorldRasterizer &rasterizer) const override;

protected:
    int score_ = 0;
    std::vector<std::shared_ptr<Obstacle>> obstacles_;
};

#endif // OBSTACLE_PATTERN_H
