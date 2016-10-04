#include "Circle.h"

Circle::Circle(double centerX, double centerY, double radius):centerX(centerX), centerY(centerY), radius(radius){};

double Circle::getCenterX() const{
    return centerX;
}

double Circle::getCenterY() const{
    return centerY;
}

double Circle::getRadius() const{
    return radius;
}

double Circle::area() const{
    return 3 * radius * radius;
}

double Circle::perimeter() const{
    return 2 * 3 * radius;
}
