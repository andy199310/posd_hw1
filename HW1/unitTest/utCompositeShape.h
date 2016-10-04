//
// Created by Green on 2016/10/4.
//

#ifndef POSD_HW1_UTCOMPOSITESHAPE_H
#define POSD_HW1_UTCOMPOSITESHAPE_H

#include "../../cppunitlite/Test.h"
#include "../CompositeShape.h"
#include "../Rectangle.h"
#include "../Circle.h"

#define EPSILON 0.001

TEST(basic_one_level, CompositeShape){
    CompositeShape compositeShape;

    Rectangle rectangle(0, 5, 10, 5);
    Circle circle(0, 1, 10);
    Triangle triangle(0, 0, 0, 1, 1, 0);

    compositeShape.add(&rectangle);
    compositeShape.add(&circle);
    compositeShape.add(&triangle);

    LONGS_EQUAL(3, compositeShape.size());

    DOUBLES_EQUAL(350.5, compositeShape.area(), EPSILON);

    DOUBLES_EQUAL(93.414, compositeShape.perimeter(), EPSILON);

    DOUBLES_EQUAL(50, compositeShape.at(0)->area(), EPSILON);

    compositeShape.remove(1);

    LONGS_EQUAL(2, compositeShape.size());

    DOUBLES_EQUAL(50.5, compositeShape.area(), EPSILON);

    DOUBLES_EQUAL(33.414, compositeShape.perimeter(), EPSILON);

}

TEST(basic_two_level, CompositeShape){
    CompositeShape compositeShapeLevelTwo;

    Rectangle rectangle(0, 5, 10, 5);
    Circle circle(0, 1, 10);
    Triangle triangle(0, 0, 0, 1, 1, 0);

    compositeShapeLevelTwo.add(&rectangle);
    compositeShapeLevelTwo.add(&circle);
    compositeShapeLevelTwo.add(&triangle);

    CompositeShape compositeShapeLevelOne;
    Rectangle rectangleOne(0, 5, 5, 5);
    compositeShapeLevelOne.add(&compositeShapeLevelTwo);
    compositeShapeLevelOne.add(&rectangleOne);

    LONGS_EQUAL(2, compositeShapeLevelOne.size());

    DOUBLES_EQUAL(375.5, compositeShapeLevelOne.area(), EPSILON);

    DOUBLES_EQUAL(113.414, compositeShapeLevelOne.perimeter(), EPSILON);

}

#endif //POSD_HW1_UTCOMPOSITESHAPE_H
