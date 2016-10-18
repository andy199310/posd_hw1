//
// Created by ChangChun-wei on 2016/10/13.
//

#include "AreaVisitor.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

void AreaVisitor::visit(CompositeMedia *media) {
    // nothing
}

void AreaVisitor::visit(ShapeMedia *media) {
    // nothing

}

void AreaVisitor::visit(Rectangle *rectangle) {
    totalArea += rectangle->area();
}

void AreaVisitor::visit(Circle *circle) {
    totalArea += circle->area();
}

void AreaVisitor::visit(Triangle *triangle) {
    totalArea += triangle->area();
}

void AreaVisitor::visit(TextMedia *media) {
    // nothing
}

void AreaVisitor::visit(Text *text) {
    // nothing
}

double AreaVisitor::getTotalArea(void) {
    return totalArea;
}
