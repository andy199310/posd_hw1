#ifndef UTRECTANGLE_H_INCLUDED
#define UTRECTANGLE_H_INCLUDED

#include "Rectangle.h"
#include "..\cppunitlite\TestHarness.h"

const double epsilon = 0.001;

TEST(basic, Rectangle){
    Rectangle rectangle(0, 5, 10, 5);


    DOUBLES_EQUAL(0, rectangle.getX(), epsilon);

    DOUBLES_EQUAL(5, rectangle.getY(), epsilon);

    DOUBLES_EQUAL(10, rectangle.getWidth(), epsilon);

    DOUBLES_EQUAL(5, rectangle.getHeight(), epsilon);
}

TEST(area, Rectangle){
    Rectangle rectangle(0, 5, 10, 5);


    DOUBLES_EQUAL(50, rectangle.area(), epsilon);
}

TEST(perimeter, Rectangle){
    Rectangle rectangle(0, 5, 10, 5);


    DOUBLES_EQUAL(30, rectangle.perimeter(), epsilon);
}

#endif // UTRECTANGLE_H_INCLUDED
