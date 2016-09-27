#include "Circle.h"

Circle::Circle(double centerX, double centerY, double radius):centerX(centerX), centerY(centerY), radius(radius){};

double const Circle::getCenterX(){
    return centerX;
}

double const Circle::getCenterY(){
    return centerY;
}

double const Circle::getRadius(){
    return radius;
}

double const Circle::area(){
    return 3 * radius * radius;
}

double const Circle::perimeter(){
    return 2 * 3 * radius;
}
