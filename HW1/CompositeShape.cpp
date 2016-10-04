//
// Created by Green on 2016/10/4.
//

#include "CompositeShape.h"

CompositeShape::CompositeShape() {

}

void CompositeShape::add(Shape * shape) {
    shapeVector.push_back(shape);
}

int CompositeShape::size() const{
    return shapeVector.size();
}

Shape *CompositeShape::at(unsigned int index) const{
    return shapeVector.at(index);
}

double CompositeShape::area() const{
    double area = 0;
    for(Shape* shape : shapeVector){
        area += shape->area();
    }
    return area;
}

double CompositeShape::perimeter() const{
    double perimeter = 0;
    for(Shape* shape : shapeVector){
        perimeter += shape->perimeter();
    }
    return perimeter;
}

void CompositeShape::remove(unsigned int index) {
    shapeVector.erase(shapeVector.begin() + index);
}
