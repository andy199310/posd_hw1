
#include <vector>
#include "Shape.h"
#include "shapeFunction.h"

double sumPerimeterOfShape(std::vector<Shape *> shapes){
    double total = 0;
    for(Shape *shpae : shapes){
        total += shpae->perimeter();
    }
    return total;
}

Shape* largestAreaShape(std::vector<Shape *> shapes){
    double largestArea = 0;
    Shape* largestAreaPointer = 0;
    for(Shape *shape : shapes){
        if(shape->area() > largestArea){
            largestArea = shape->area();
            largestAreaPointer = shape;
        }
    }
    return largestAreaPointer;
}
