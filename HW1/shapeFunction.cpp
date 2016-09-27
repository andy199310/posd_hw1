
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

std::vector<Shape *> sortShapesByArea(std::vector<Shape *> shapes){
    for(unsigned int i=0; i<shapes.size()-1; i++){
        for(unsigned int j=0; j<shapes.size()-1-i; j++){
            if (shapes.at(j)->area() > shapes.at(j+1)->area()){
                std::swap(shapes.at(j), shapes.at(j+1));
            }
        }
    }
    return shapes;
}
