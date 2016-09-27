#ifndef UTTRIANGLE_H_INCLUDED
#define UTTRIANGLE_H_INCLUDED

#include "Triangle.h"
#include "..\cppunitlite\TestHarness.h"

//const double epsilon = 0.000001;

TEST(basic, Triangle){
    Triangle triangle(0, 0, 0, 1, 1, 0);
}

TEST(area, Triangle){
    Triangle triangle(0, 0, 0, 1, 1, 0);

    DOUBLES_EQUAL(0.5, triangle.area(), epsilon);
}

TEST(perimeter, Triangle){
    Triangle triangle(0, 0, 0, 1, 1, 0);


    DOUBLES_EQUAL(3.414, triangle.perimeter(), epsilon);
}

#endif // UTTRIANGLE_H_INCLUDED
