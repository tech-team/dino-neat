#ifndef RECTANGULAR_OBSTACLE_H
#define RECTANGULAR_OBSTACLE_H

#include "obstacle.h"
#include "rectangular_object.h"


class World;

class RectangularObstacle
        : virtual public Obstacle,
          public RectangularObject {
public:
    RectangularObstacle(World& world);

    virtual void update(float dt) override;

    bool isVisible() override;
};

#endif // RECTANGULAR_OBSTACLE_H
