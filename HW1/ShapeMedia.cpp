//
// Created by ChangChun-wei on 2016/10/7.
//

#include "ShapeMedia.h"

void ShapeMedia::add(Shape *shape) {
    shapeVector.push_back(shape);
}

int ShapeMedia::size() const {
    return shapeVector.size();
}

void ShapeMedia::accept(MediaVisitor &visitor) {
    for(Shape* shapeMedia : shapeVector){
        shapeMedia->accept(visitor);
    }
}

