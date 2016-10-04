//
// Created by Green on 2016/10/4.
//

#ifndef POSD_HW1_COMPOSITESHAPE_H
#define POSD_HW1_COMPOSITESHAPE_H


#include <vector>
#include "Shape.h"

class CompositeShape : public Shape{
public:
    CompositeShape();

    void add(Shape *shape);
    void remove(unsigned int index);
    int size() const;
    Shape* at(unsigned int index) const;

    double area() const;
    double perimeter() const;

private:
    std::vector<Shape *> shapeVector;

};


#endif //POSD_HW1_COMPOSITESHAPE_H
