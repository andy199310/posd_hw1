#ifndef UTTRIANGLE_H_INCLUDED
#define UTTRIANGLE_H_INCLUDED

#define EPSILON 0.001

#include "../Triangle.h"
#include "../../cppunitlite/TestHarness.h"

TEST(basic, Triangle){
    Triangle triangle(0, 0, 0, 1, 1, 0);
    CHECK(false);
}

TEST(area, Triangle){
    Triangle triangle(0, 0, 0, 1, 1, 0);

    DOUBLES_EQUAL(0.5, triangle.area(), EPSILON);
}

TEST(perimeter, Triangle){
    Triangle triangle(0, 0, 0, 1, 1, 0);


    DOUBLES_EQUAL(3.414, triangle.perimeter(), EPSILON);
}

#endif // UTTRIANGLE_H_INCLUDED
