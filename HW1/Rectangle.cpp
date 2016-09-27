#include "Rectangle.h"

Rectangle::Rectangle(double x, double y, double width, double height):x(x), y(y), width(width), height(height){};

double const Rectangle::getX(){
    return x;
}

double const Rectangle::getY(){
    return y;
}

double const Rectangle::getWidth(){
    return width;
}

double const Rectangle::getHeight(){
    return height;
}

double const Rectangle::area(){
    return width * height;
}

double const Rectangle::perimeter(){
    return 2 * (width + height);
}
