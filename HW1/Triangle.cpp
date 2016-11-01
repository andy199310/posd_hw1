#include <math.h>
#include <sstream>

#include "Triangle.h"
#include "AreaVisitor.h"

Triangle::Triangle(double point1X, double point1Y, double point2X, double point2Y, double point3X, double point3Y):
    point1X(point1X), point1Y(point1Y), point2X(point2X), point2Y(point2Y), point3X(point3X), point3Y(point3Y){
    if(this->area() == 0){
        throw "Giving numbers cannot create a Triangle.";
    }
}

double Triangle::area() const{
    double line1 = sqrt((point1X - point2X) * (point1X - point2X) + (point1Y - point2Y) * (point1Y - point2Y));
    double line2 = sqrt((point2X - point3X) * (point2X - point3X) + (point2Y - point3Y) * (point2Y - point3Y));
    double line3 = sqrt((point3X - point1X) * (point3X - point1X) + (point3Y - point1Y) * (point3Y - point1Y));

    double s = (line1 + line2 + line3) / 2;

    return sqrt(s * (s - line1) * (s - line2) * (s - line3));
}

double Triangle::perimeter() const{
    double line1 = sqrt((point1X - point2X) * (point1X - point2X) + (point1Y - point2Y) * (point1Y - point2Y));
    double line2 = sqrt((point2X - point3X) * (point2X - point3X) + (point2Y - point3Y) * (point2Y - point3Y));
    double line3 = sqrt((point3X - point1X) * (point3X - point1X) + (point3Y - point1Y) * (point3Y - point1Y));

    return line1 + line2 + line3;
}

void Triangle::accept(MediaVisitor *visitor) {
    visitor->visit(this);
}

std::string Triangle::toString() {
    std::stringstream stringStream;
    stringStream << "t(" << point1X << " " << point1Y << " " << point2X << " " << point2Y << " "<< point3X << " " << point3Y << ") ";
    return stringStream.str();
}
