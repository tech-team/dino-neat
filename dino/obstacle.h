#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "world_object.h"

class World;

class Obstacle : virtual public WorldObject {
public:
    Obstacle(World& world);
	
    virtual bool isVisible() = 0;

    virtual void set_passed(bool passed);
    virtual bool is_passed() const;

protected:
    bool passed_ = false;
};

#endif // OBSTACLE_H
