cmake_minimum_required(VERSION 3.6)
project(posd_hw1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    HW1/Circle.cpp
    HW1/Circle.h
    HW1/main.cpp
    HW1/Rectangle.cpp
    HW1/Rectangle.h
    HW1/Shape.h
    HW1/shapeFunction.cpp
    HW1/shapeFunction.h
    HW1/Triangle.cpp
    HW1/Triangle.h
        HW1/unitTest/utCircle.h
        HW1/unitTest/utRectangle.h
        HW1/unitTest/utshapeFunctoin.h
        HW1/unitTest/utTriangle.h HW1/unitTest/utMain.h)

add_executable(posd_hw1 ${SOURCE_FILES})

target_link_libraries(posd_hw1 ${CMAKE_SOURCE_DIR}/cppunitlite/libCppUnitLite.a)