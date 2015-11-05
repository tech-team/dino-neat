#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "point.h"

class WorldObject {
public:
    WorldObject();

    Point origin() const;
    double width() const;
    double height() const;

    void set_origin(Point origin);
    void set_width(double width);
    void set_height(double height);

private:
    Point origin_;
    double width_;
    double height_;
};

#endif // WORLDOBJECT_H
