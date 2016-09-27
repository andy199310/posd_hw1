#ifndef SHAPEFUNCTION_H_INCLUDED
#define SHAPEFUNCTION_H_INCLUDED

#include <vector>
#include "Shape.h"

double sumPerimeterOfShape(std::vector<Shape *> shapes);

Shape* largestAreaShape(std::vector<Shape *> shapes);

std::vector<Shape *> sortShapesByArea(std::vector<Shape *> shapes);

#endif // SHAPEFUNCTION_H_INCLUDED
