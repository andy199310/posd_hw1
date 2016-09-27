#ifndef UTCIRCLE_H_INCLUDED
#define UTCIRCLE_H_INCLUDED

#define EPSILON 0.001

#include "Circle.h"
#include "..\cppunitlite\TestHarness.h"

TEST(basic, Circle){
    Circle circle(0, 1, 10);


    DOUBLES_EQUAL(0, circle.getCenterX(), EPSILON);

    DOUBLES_EQUAL(1, circle.getCenterY(), EPSILON);

    DOUBLES_EQUAL(10, circle.getRadius(), EPSILON);
}

TEST(area, Circle){
    Circle circle(0, 1, 10);


    DOUBLES_EQUAL(300, circle.area(), EPSILON);
}

TEST(perimeter, Circle){
    Circle circle(0, 1, 10);


    DOUBLES_EQUAL(60, circle.perimeter(), EPSILON);
}


#endif // UTCIRCLE_H_INCLUDED
