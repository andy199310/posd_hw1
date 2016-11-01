//
// Created by Green on 2016/10/4.
//

#ifndef POSD_HW1_UTCOMPOSITESHAPE_H
#define POSD_HW1_UTCOMPOSITESHAPE_H

#include "../DescriptionVisitor.h"
#include "../../cppunitlite/Test.h"
#include "../Triangle.h"
#include "../CompositeMedia.h"
#include "../Rectangle.h"
#include "../Circle.h"
#include "../ShapeMedia.h"

#define EPSILON 0.001

TEST(basic_one_level, CompositeShape){


    Rectangle rectangle(0, 5, 10, 5);
    Circle circle(0, 1, 10);
    Triangle triangle(0, 0, 0, 1, 1, 0);

    ShapeMedia shapeMedia1(&rectangle);
    ShapeMedia shapeMedia2(&circle);
    ShapeMedia shapeMedia3(&triangle);

    CompositeMedia compositeMedia;
    compositeMedia.add(&shapeMedia1);
    compositeMedia.add(&shapeMedia2);
    compositeMedia.add(&shapeMedia3);

    LONGS_EQUAL(3, compositeMedia.size());
}

TEST(remove, CompositeShape){

    ShapeMedia *shapeMediaRectangle1 = new ShapeMedia(new Rectangle(10, 0, 15, 5));
    ShapeMedia *shapeMediaCircle1 = new ShapeMedia(new Circle(12, 5, 2));
    CompositeMedia *compositeMedia1 = new CompositeMedia;
    compositeMedia1->add(shapeMediaRectangle1);
    compositeMedia1->add(shapeMediaCircle1);

    ShapeMedia *shapeMediaRectangle2 = new ShapeMedia(new Rectangle(0, 0, 25, 20));
    CompositeMedia *compositeMedia2 = new CompositeMedia;
    compositeMedia2->add(compositeMedia1);
    compositeMedia2->add(shapeMediaRectangle2);

    ShapeMedia *shapeMediaTriangle = new ShapeMedia(new Triangle(0, 20, 16, 32, 25, 20));

    CompositeMedia *compositeMedia3 = new CompositeMedia;
    compositeMedia3->add(compositeMedia2);
    compositeMedia3->add(shapeMediaTriangle);

    DescriptionVisitor descriptionVisitor;
    compositeMedia3->accept(&descriptionVisitor);

    CHECK("combo(combo(combo(r(10 0 15 5) c(12 5 2) )r(0 0 25 20) )t(0 20 16 32 25 20) )" == descriptionVisitor.getDescription());

    compositeMedia3->remove(shapeMediaRectangle2);

    DescriptionVisitor descriptionVisitorAfter;
    compositeMedia3->accept(&descriptionVisitorAfter);

    CHECK("combo(combo(combo(r(10 0 15 5) c(12 5 2) ))t(0 20 16 32 25 20) )" == descriptionVisitorAfter.getDescription());

}

#endif //POSD_HW1_UTCOMPOSITESHAPE_H
