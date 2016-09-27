#ifndef UTSHAPEFUNCTOIN_H_INCLUDED
#define UTSHAPEFUNCTOIN_H_INCLUDED

#define EPSILON 0.001

#include <vector>
#include "shapeFunction.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include "..\cppunitlite\TestHarness.h"

TEST(sumPerimeterOfShape, shapeFunctoin){
    std::vector<Shape *> shapes;

    Rectangle rectangle(0, 5, 10, 5);
    Circle circle(0, 1, 10);
    Triangle triangle(0, 0, 0, 1, 1, 0);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);
    shapes.push_back(&triangle);


    DOUBLES_EQUAL(93.414, sumPerimeterOfShape(shapes), EPSILON)
}

TEST(largestAreaShape, shapeFunctoin){
    std::vector<Shape *> shapes;

    Rectangle rectangle(0, 5, 10, 5);
    Circle circle(0, 1, 10);
    Triangle triangle(0, 0, 0, 1, 1, 0);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);
    shapes.push_back(&triangle);

    DOUBLES_EQUAL(300, largestAreaShape(shapes)->area(), EPSILON)
}

#endif // UTSHAPEFUNCTOIN_H_INCLUDED
