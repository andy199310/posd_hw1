//
// Created by ChangChun-wei on 2016/10/14.
//

#ifndef POSD_HW1_UTAREAVISITOR_H
#define POSD_HW1_UTAREAVISITOR_H

#define EPSILON 0.001

#include "../Rectangle.h"
#include "../Triangle.h"
#include "../ShapeMedia.h"
#include "../CompositeMedia.h"
#include "../AreaVisitor.h"
#include "../PerimeterVisitor.h"
#include "../../cppunitlite/TestHarness.h"

TEST(totalArea, AreaVisitor){
    Rectangle middleRectangle(0, 0, 2, 3.464);
    Triangle leftTriangle(0, 0, -1, 1.732, 0, 3.464);
    Triangle rightTriangle(2, 0, 2, 3.464, 3, 1.732);
    ShapeMedia hexagonShape;
    hexagonShape.add(&middleRectangle);
    hexagonShape.add(&leftTriangle);
    hexagonShape.add(&rightTriangle);

    CompositeMedia hexagonComposite;
    hexagonComposite.add(&hexagonShape);

    AreaVisitor hexagonAreaVisitor;
    hexagonComposite.accept(&hexagonAreaVisitor);

    DOUBLES_EQUAL(10.392, hexagonAreaVisitor.getTotalArea(), EPSILON);
}

#endif //POSD_HW1_UTAREAVISITOR_H
