//
// Created by ChangChun-wei on 2016/10/14.
//

#ifndef POSD_HW1_UTPERIMETERVISITOR_H
#define POSD_HW1_UTPERIMETERVISITOR_H

#define EPSILON 0.001

#include "../Rectangle.h"
#include "../Triangle.h"
#include "../ShapeMedia.h"
#include "../CompositeMedia.h"
#include "../PerimeterVisitor.h"
#include "../../cppunitlite/TestHarness.h"

TEST(totalPerimeter, PerimeterVisitor){
    Rectangle middleRectangle(0, 0, 2, 3.464);
    Triangle leftTriangle(0, 0, -1, 1.732, 0, 3.464);
    Triangle rightTriangle(2, 0, 2, 3.464, 3, 1.732);
    ShapeMedia shapeMediaMiddleRectangle(&middleRectangle);
    ShapeMedia shapeMediaLeftTriangle(&leftTriangle);
    ShapeMedia shapeMediaRightTriangle(&rightTriangle);

    CompositeMedia hexagonComposite;
    hexagonComposite.add(&shapeMediaMiddleRectangle);
    hexagonComposite.add(&shapeMediaLeftTriangle);
    hexagonComposite.add(&shapeMediaRightTriangle);

    PerimeterVisitor hexagonPerimeterVisitor;
    hexagonComposite.accept(&hexagonPerimeterVisitor);

    DOUBLES_EQUAL(25.8558, hexagonPerimeterVisitor.getTotalPerimeter(), EPSILON);
}

#endif //POSD_HW1_UTPERIMETERVISITOR_H
