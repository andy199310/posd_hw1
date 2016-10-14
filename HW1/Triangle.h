#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Shape.h"

class Triangle : public Shape{
public:
    Triangle(double point1X, double point1Y, double point2X, double point2Y, double point3X, double point3Y);

    double area() const;

    double perimeter() const;

    virtual void accept(MediaVisitor &visitor) override;

private:
    double point1X;
    double point1Y;
    double point2X;
    double point2Y;
    double point3X;
    double point3Y;
};

#endif // TRIANGLE_H_INCLUDED
