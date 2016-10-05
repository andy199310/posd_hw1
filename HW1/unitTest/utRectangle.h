#ifndef UTRECTANGLE_H_INCLUDED
#define UTRECTANGLE_H_INCLUDED

#define EPSILON 0.001

#include "../Rectangle.h"
#include "../../cppunitlite/TestHarness.h"

TEST(basic, Rectangle){
    Rectangle rectangle(0, 5, 10, 5);


    DOUBLES_EQUAL(0, rectangle.getX(), EPSILON);

    DOUBLES_EQUAL(5, rectangle.getY(), EPSILON);

    DOUBLES_EQUAL(10, rectangle.getWidth(), EPSILON);

    DOUBLES_EQUAL(5, rectangle.getHeight(), EPSILON);
}

TEST(exceptions, Rectangle){
    try{
        Rectangle rectangle(0, 0, -1, 0);
        CHECK(false);
    }catch (char const* message){
        CHECK(true);
    }
}

TEST(area, Rectangle){
    Rectangle rectangle(0, 5, 10, 5);


    DOUBLES_EQUAL(50, rectangle.area(), EPSILON);
}

TEST(perimeter, Rectangle){
    Rectangle rectangle(0, 5, 10, 5);


    DOUBLES_EQUAL(30, rectangle.perimeter(), EPSILON);
}

#endif // UTRECTANGLE_H_INCLUDED
