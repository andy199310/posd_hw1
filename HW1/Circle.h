#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Shape.h"

class Circle : public Shape{
public:
    Circle(double centerX, double centerY, double radius);

    double const getCenterX();
    double const getCenterY();
    double const getRadius();

    double const area();

    double const perimeter();

private:
    double centerX;
    double centerY;
    double radius;
};


#endif // CIRCLE_H_INCLUDED
