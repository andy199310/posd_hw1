//
// Created by ChangChun-wei on 2016/10/7.
//

#include "ShapeMedia.h"
#include "MediaVisitor.h"

void ShapeMedia::add(Shape *shape) {
    shapeVector.push_back(shape);
}

int ShapeMedia::size() const {
    return shapeVector.size();
}

void ShapeMedia::accept(MediaVisitor *visitor) {
    for(Shape* shapeMedia : shapeVector){
        shapeMedia->accept(visitor);
    }
    visitor->visit(this);
}

void ShapeMedia::add(Media *media) {
    throw "Cannot add Media with ShapeMedia";
}

