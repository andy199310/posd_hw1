#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle : Shape{
public:
    Rectangle(double x, double y, double width, double height);

    double const getX();
    double const getY();
    double const getWidth();
    double const getHeight();

    double const area();

    double const perimeter();


private:
    double x;
    double y;
    double width;
    double height;
};


#endif // RECTANGLE_H_INCLUDED
