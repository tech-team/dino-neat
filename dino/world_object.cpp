#include "world_object.h"

WorldObject::WorldObject() {

}

Point WorldObject::origin() const {
    return origin_;
}

double WorldObject::width() const {
    return width_;
}

double WorldObject::height() const {
    return height_;
}

void WorldObject::set_origin(Point origin) {
    origin_ = origin;
}

void WorldObject::set_width(double width) {
    width_ = width;
}

void WorldObject::set_height(double height) {
    height_ = height;
}
