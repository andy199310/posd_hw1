//
// Created by ChangChun-wei on 2016/10/14.
//

#ifndef POSD_HW1_UTPERIMETERVISITOR_H
#define POSD_HW1_UTPERIMETERVISITOR_H

#define EPSILON 0.001

#include "HW1/Rectangle.h"
#include "HW1/Triangle.h"
#include "HW1/ShapeMedia.h"
#include "HW1/CompositeMedia.h"
#include "HW1/PerimeterVisitor.h"
#include "../../cppunitlite/TestHarness.h"

TEST(totalPerimeter, PerimeterVisitor){
    Rectangle middleRectangle(0, 3.464, 2, 3.464);
    Triangle leftTriangle(0, 0, -1, 1.732, 0, 3.464);
    Triangle rightTriangle(2, 0, 2, 3.464, 3, 1.732);
    ShapeMedia hexagonShape;
    hexagonShape.add(&middleRectangle);
    hexagonShape.add(&leftTriangle);
    hexagonShape.add(&rightTriangle);

    CompositeMedia hexagonComposite;
    hexagonComposite.add(&hexagonShape);

    PerimeterVisitor hexagonPerimeterVisitor;
    hexagonComposite.accept(&hexagonPerimeterVisitor);

    DOUBLES_EQUAL(25.8558, hexagonPerimeterVisitor.getTotalPerimeter(), EPSILON);
}

#endif //POSD_HW1_UTPERIMETERVISITOR_H
