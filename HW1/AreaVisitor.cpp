//
// Created by ChangChun-wei on 2016/10/13.
//

#include "AreaVisitor.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

void AreaVisitor::visit(Rectangle *rectangle) {
    totalArea += rectangle->area();
}

void AreaVisitor::visit(Circle *circle) {
    totalArea += circle->area();
}

void AreaVisitor::visit(Triangle *triangle) {
    totalArea += triangle->area();
}

double AreaVisitor::getTotalArea(void) {
    return totalArea;
}
