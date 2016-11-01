#include <sstream>
#include "Circle.h"

#include "AreaVisitor.h"

Circle::Circle(double centerX, double centerY, double radius):centerX(centerX), centerY(centerY), radius(radius){
    if(radius <= 0){
        throw "Giving numbers cannot create a Circle.";
    }
};

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

void Circle::accept(MediaVisitor *visitor) {
    visitor->visit(this);
}

std::string Circle::toString() {
    std::stringstream stringStream;
    stringStream << "c(" << centerX << " " << centerY << " " << radius << ") ";
    return stringStream.str();
}
