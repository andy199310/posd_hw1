//
// Created by ChangChun-wei on 2016/10/7.
//

#include "ShapeMedia.h"
#include "MediaVisitor.h"

void ShapeMedia::accept(MediaVisitor *visitor) {
    _shape->accept(visitor);
    visitor->visit(this);
}

void ShapeMedia::add(Media *media) {
    throw "Cannot add Media with ShapeMedia";
}

ShapeMedia::ShapeMedia(Shape *shape) {
    _shape = shape;
}

Shape *ShapeMedia::getShape() {
    return _shape;
}

bool ShapeMedia::remove(Media *removeMedia) {
    return false;
}

