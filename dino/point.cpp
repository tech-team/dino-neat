#include "point.h"

#include <cmath>


Point::Point()
    : Point(0, 0) {

}

Point::Point(double x, double y)
    : x_(x), y_(y) {

}

double Point::x() const {
    return x_;
}

double Point::y() const {
    return y_;
}


void Point::set_x(double x) {
    x_ = x;
}

void Point::set_y(double y) {
    y_ = y;
}

double Point::distanceTo(const Point &other) const {
    return distance(*this, other);
}

double Point::distance(const Point &a, const Point &b) {
    return std::sqrt(
                (a.x_ - b.x_) * (a.x_ - b.x_) +
                (a.y_ - b.y_) * (a.y_ - b.y_)
           );
}
