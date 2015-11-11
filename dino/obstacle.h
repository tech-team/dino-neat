#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "rectangular_object.h"
#include "world.h"

class Obstacle : public WorldObject {
public:
    Obstacle(World& world);
	
    virtual bool isVisible() = 0;

    virtual void set_passed(bool passed);
    virtual bool is_passed() const;

private:
    bool passed_ = false;
};

#endif // OBSTACLE_H
