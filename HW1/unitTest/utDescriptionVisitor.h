//
// Created by Green on 2016/10/28.
//

#ifndef POSD_HW1_UTDESCRIPTIONVISITOR_H
#define POSD_HW1_UTDESCRIPTIONVISITOR_H

#define EPSILON 0.001

#include "../Circle.h"
#include "../DescriptionVisitor.h"
#include "../Rectangle.h"
#include "../Triangle.h"
#include "../ShapeMedia.h"
#include "../CompositeMedia.h"
#include "../../cppunitlite/TestHarness.h"

TEST(oneLevelOneItem, DescriptionVisitor){
    Rectangle rectangle(0, 0, 10, 5);
    ShapeMedia shapeMedia(&rectangle);

    CompositeMedia compositeMedia;
    compositeMedia.add(&shapeMedia);

    DescriptionVisitor descriptionVisitor;
    compositeMedia.accept(&descriptionVisitor);

    CHECK("combo(r(0 0 10 5) )" == descriptionVisitor.getDescription());
}

TEST(oneLevelTwoItem, DescriptionVisitor){
    Rectangle rectangle(0, 0, 10, 5);
    Circle circle(0, 0, 10);
    ShapeMedia shapeMediaRectangle(&rectangle);
    ShapeMedia shapeMediaCircle(&circle);

    CompositeMedia compositeMedia;
    compositeMedia.add(&shapeMediaRectangle);
    compositeMedia.add(&shapeMediaCircle);

    DescriptionVisitor descriptionVisitor;
    compositeMedia.accept(&descriptionVisitor);

    CHECK("combo(r(0 0 10 5) c(0 0 10) )" == descriptionVisitor.getDescription());
}

TEST(twoLevelTwoItem, DescriptionVisitor){
    Rectangle rectangle(0, 0, 10, 5);
    Circle circle(0, 0, 10);
    ShapeMedia shapeMediaRectangle(&rectangle);
    ShapeMedia shapeMediaCircle(&circle);
    Rectangle rectangle2(1, 1, 1, 1);
    ShapeMedia shapeMediaRectangle2(&rectangle2);
    CompositeMedia compositeMedia2;
    compositeMedia2.add(&shapeMediaRectangle);
    compositeMedia2.add(&shapeMediaCircle);

    CompositeMedia compositeMedia3;
    compositeMedia3.add(&shapeMediaRectangle2);

    CompositeMedia compositeMedia;
    compositeMedia.add(&compositeMedia2);
    compositeMedia.add(&compositeMedia3);

    DescriptionVisitor descriptionVisitor;
    compositeMedia.accept(&descriptionVisitor);

    CHECK("combo(combo(r(0 0 10 5) c(0 0 10) )combo(r(1 1 1 1) ))" == descriptionVisitor.getDescription());
}

#endif //POSD_HW1_UTDESCRIPTIONVISITOR_H
