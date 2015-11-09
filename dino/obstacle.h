#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "rectangular_object.h"
#include "world.h"

class Obstacle : public RectangularObject {
public:
    Obstacle(World& world);

    virtual void update(float dt) override;

    bool isVisible();
};

#endif // OBSTACLE_H
