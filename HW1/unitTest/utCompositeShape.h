//
// Created by Green on 2016/10/4.
//

#ifndef POSD_HW1_UTCOMPOSITESHAPE_H
#define POSD_HW1_UTCOMPOSITESHAPE_H

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

TEST(basic_two_level, CompositeShape){
//    CompositeMedia compositeShapeLevelTwo;
//
//    Rectangle rectangle(0, 5, 10, 5);
//    Circle circle(0, 1, 10);
//    Triangle triangle(0, 0, 0, 1, 1, 0);
//
//    compositeShapeLevelTwo.add(&rectangle);
//    compositeShapeLevelTwo.add(&circle);
//    compositeShapeLevelTwo.add(&triangle);
//
//    CompositeMedia compositeShapeLevelOne;
//    Rectangle rectangleOne(0, 5, 5, 5);
//    compositeShapeLevelOne.add(&compositeShapeLevelTwo);
//    compositeShapeLevelOne.add(&rectangleOne);
//
//    LONGS_EQUAL(2, compositeShapeLevelOne.size());
//
//    DOUBLES_EQUAL(375.5, compositeShapeLevelOne.area(), EPSILON);
//
//    DOUBLES_EQUAL(113.414, compositeShapeLevelOne.perimeter(), EPSILON);

}

#endif //POSD_HW1_UTCOMPOSITESHAPE_H
