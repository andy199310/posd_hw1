#ifndef UTCIRCLE_H_INCLUDED
#define UTCIRCLE_H_INCLUDED

#include "Circle.h"
#include "..\cppunitlite\TestHarness.h"

//const double epsilon = 0.000001;

TEST(basic, Circle){
    Circle circle(0, 1, 10);


    DOUBLES_EQUAL(0, circle.getCenterX(), epsilon);

    DOUBLES_EQUAL(1, circle.getCenterY(), epsilon);

    DOUBLES_EQUAL(10, circle.getRadius(), epsilon);
}

TEST(area, Circle){
    Circle circle(0, 1, 10);


    DOUBLES_EQUAL(300, circle.area(), epsilon);
}

TEST(perimeter, Circle){
    Circle circle(0, 1, 10);


    DOUBLES_EQUAL(60, circle.perimeter(), epsilon);
}


#endif // UTCIRCLE_H_INCLUDED
