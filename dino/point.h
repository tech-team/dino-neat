#ifndef POINT_H
#define POINT_H


class Point {
public:
    Point();
    Point(double x, double y);

    double x() const;
    double y() const;


    void set_x(double x);
    void set_y(double y);

    double distanceTo(const Point &other) const;

    static double distance(const Point &a, const Point &b);

private:
    double x_;
    double y_;
};

#endif // POINT_H
