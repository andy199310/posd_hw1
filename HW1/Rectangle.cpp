#include <sstream>
#include "Rectangle.h"

#include "AreaVisitor.h"

Rectangle::Rectangle(double x, double y, double width, double height):x(x), y(y), width(width), height(height){
    if(width <= 0 || height <= 0){
        throw "Giving numbers cannot create a Rectangle.";
    }
};

double Rectangle::getX() const{
    return x;
}

double Rectangle::getY() const{
    return y;
}

double Rectangle::getWidth() const{
    return width;
}

double Rectangle::getHeight() const{
    return height;
}

double Rectangle::area() const{
    return width * height;
}

double Rectangle::perimeter() const{
    return 2 * (width + height);
}

void Rectangle::accept(MediaVisitor *visitor) {
    visitor->visit(this);
}

std::string Rectangle::toString() {
    std::stringstream stringStream;
    stringStream << "Rectangle(" << x << "," << y << "," << width << "," << height << ")";
    return stringStream.str();
}

