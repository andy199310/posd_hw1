//
// Created by ChangChun-wei on 2016/10/13.
//

#ifndef POSD_HW1_MEDIAVISITOR_H
#define POSD_HW1_MEDIAVISITOR_H

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

class MediaVisitor {
public:

    virtual void visit(Rectangle) = 0;
    virtual void visit(Circle) = 0;
    virtual void visit(Triangle) = 0;
};
#endif //POSD_HW1_MEDIAVISITOR_H
