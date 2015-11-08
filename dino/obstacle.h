#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "world_object.h"

class Obstacle : public WorldObject {
public:
    Obstacle(World& world);

    virtual const sf::Drawable& getDrawable() const override;
    virtual void update(float dt) override;

    virtual void moveTo(sf::Vector2f pos) override;
    virtual void move(sf::Vector2f delta) override;

    bool isVisible();

private:
    sf::RectangleShape shape_;
};

#endif // OBSTACLE_H
