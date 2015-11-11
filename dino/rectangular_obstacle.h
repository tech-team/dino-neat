#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "obstacle.h"
#include "rectangular_object.h"
#include "world.h"

class RectangularObstacle : public RectangularObject, public Obstacle {
public:
    Rectangular(World& world);

    virtual void update(float dt) override;

    bool isVisible() override;

    void set_passed(bool passed) override;
    bool is_passed() const override;

    virtual bool collidesWith(RectangularObstacle& object) override;

private:
    //bool passed_ = false;
};

#endif // OBSTACLE_H
