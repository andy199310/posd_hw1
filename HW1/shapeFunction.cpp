
#include <vector>
#include "Shape.h"
#include "shapeFunction.h"

double sumPerimeterOfShape(std::vector<Shape *> shapes){
    double total = 0;
    for (Shape *shpae : shapes)
        total += shpae->perimeter();
    return total;
}
