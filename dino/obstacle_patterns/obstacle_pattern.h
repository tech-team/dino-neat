#ifndef OBSTACLE_PATTERN_H
#define OBSTACLE_PATTERN_H

#include <memory>
#include <vector>

#include "obstacle.h"

class ObstaclePattern : public Obstacle {
public:
    ObstaclePattern(World& world);

    virtual void update(float dt) override;
    virtual void draw(sf::RenderWindow& window) override;

    virtual void moveTo(sf::Vector2f pos) override;
    virtual void move(sf::Vector2f delta) override;
    virtual void rasterize(PlainWorld &raster, WorldRasterizer &rasterizer) const override;

    virtual bool isVisible() override;

    virtual bool collidesWith(const RectangularObject &object) const override;

protected:
    int score_ = 0;
    std::vector<std::shared_ptr<Obstacle>> obstacles_;
};

#endif // OBSTACLE_PATTERN_H
