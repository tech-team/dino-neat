#ifndef OBSTACLEPATTERN_H
#define OBSTACLEPATTERN_H

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

private:
    int score_ = 0;
    std::vector<std::shared_ptr<Obstacle>> obstacles_;
};

#endif // OBSTACLEPATTERN_H
