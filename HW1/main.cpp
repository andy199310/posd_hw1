#include <iostream>

#include "..\cppunitlite\TestHarness.h"

#include "utRectangle.h"
#include "utCircle.h"
#include "utTriangle.h"
#include "utshapeFunctoin.h"

#include <vector>

#include "Shape.h"

int main(){
    TestResult tr;
    TestRegistry::runAllTests(tr);

    std::vector<Shape *> shapes;

    Rectangle rectangle(0, 5, 10, 5);
    Circle circle(0, 1, 10);
    Triangle triangle(0, 0, 0, 1, 1, 0);
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);
    shapes.push_back(&triangle);

    std::cout << sumPerimeterOfShape(shapes);
}
