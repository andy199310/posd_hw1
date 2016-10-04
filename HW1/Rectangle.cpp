#include "Rectangle.h"

Rectangle::Rectangle(double x, double y, double width, double height):x(x), y(y), width(width), height(height){};

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
