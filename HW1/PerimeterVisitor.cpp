//
// Created by ChangChun-wei on 2016/10/14.
//

#include "PerimeterVisitor.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

void PerimeterVisitor::visit(Rectangle *rectangle) {
    totalPerimeter += rectangle->perimeter();
}

void PerimeterVisitor::visit(Circle *circle) {
    totalPerimeter += circle->perimeter();
}

void PerimeterVisitor::visit(Triangle *triangle) {
    totalPerimeter += triangle->perimeter();
}

double PerimeterVisitor::getTotalPerimeter() {
    return totalPerimeter;
}
