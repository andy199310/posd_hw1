//
// Created by Green on 2016/10/28.
//

#ifndef POSD_HW1_UTDESCRIPTIONVISITOR_H
#define POSD_HW1_UTDESCRIPTIONVISITOR_H

#define EPSILON 0.001

#include "../DescriptionVisitor.h"
#include "../Rectangle.h"
#include "../Triangle.h"
#include "../ShapeMedia.h"
#include "../CompositeMedia.h"
#include "../../cppunitlite/TestHarness.h"

TEST(oneLevelOneItem, DescriptionVisitor){
    Rectangle rectangle(0, 0, 10, 5);
    ShapeMedia shapeMedia;
    shapeMedia.add(&rectangle);

    CompositeMedia compositeMedia;
    compositeMedia.add(&shapeMedia);

    DescriptionVisitor descriptionVisitor;
    compositeMedia.accept(&descriptionVisitor);

    CHECK("CompositeMedia(ShapeMedia(Rectangle(0,0,10,5)))" == descriptionVisitor.getDescription());
}

TEST(oneLevelTwoItem, DescriptionVisitor){
    Rectangle rectangle(0, 0, 10, 5);
    Circle circle(0, 0, 10);
    ShapeMedia shapeMedia;
    shapeMedia.add(&rectangle);
    shapeMedia.add(&circle);

    CompositeMedia compositeMedia;
    compositeMedia.add(&shapeMedia);

    DescriptionVisitor descriptionVisitor;
    compositeMedia.accept(&descriptionVisitor);

    CHECK("CompositeMedia(ShapeMedia(Rectangle(0,0,10,5)Circle(0,0,10)))" == descriptionVisitor.getDescription());
}

TEST(twoLevelTwoItem, DescriptionVisitor){
    Rectangle rectangle(0, 0, 10, 5);
    Circle circle(0, 0, 10);
    ShapeMedia shapeMedia;
    shapeMedia.add(&rectangle);
    shapeMedia.add(&circle);

    Rectangle rectangle2(1, 1, 1, 1);
    ShapeMedia shapeMedia2;
    shapeMedia2.add(&rectangle2);

    CompositeMedia compositeMedia2;
    compositeMedia2.add(&shapeMedia2);

    CompositeMedia compositeMedia;
    compositeMedia.add(&shapeMedia);
    compositeMedia.add(&compositeMedia2);

    DescriptionVisitor descriptionVisitor;
    compositeMedia.accept(&descriptionVisitor);

    CHECK("CompositeMedia(ShapeMedia(Rectangle(0,0,10,5)Circle(0,0,10))CompositeMedia(ShapeMedia(Rectangle(1,1,1,1))))" == descriptionVisitor.getDescription());
}

#endif //POSD_HW1_UTDESCRIPTIONVISITOR_H
