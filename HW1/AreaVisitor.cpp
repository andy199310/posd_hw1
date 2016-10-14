//
// Created by ChangChun-wei on 2016/10/13.
//

#include "AreaVisitor.h"

void AreaVisitor::visit(Rectangle rectangle) {
    totlaArea += rectangle.area();
}

void AreaVisitor::visit(Circle circle) {
    totlaArea += circle.area();
}

void AreaVisitor::visit(Triangle triangle) {
    totlaArea += triangle.area();
}
