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
        HW1/unitTest/utTriangle.h HW1/unitTest/utMain.h HW1/CompositeShape.cpp HW1/CompositeShape.h HW1/unitTest/utCompositeShape.h)

add_executable(posd_hw1 ${SOURCE_FILES})

# for CMake to build libCppUnitLite.a file (PS: need to dig into cache folder for lib)
# add_library(libCppUnitLite cppunitlite/Failure.cpp cppunitlite/Failure.h cppunitlite/SimpleString.h cppunitlite/SimpleString.cpp cppunitlite/Test.h cppunitlite/Test.cpp cppunitlite/TestResult.h cppunitlite/TestRegistry.cpp cppunitlite/TestResult.cpp cppunitlite/TestRegistry.h)

target_link_libraries(posd_hw1 ${CMAKE_SOURCE_DIR}/cppunitlite/libCppUnitLite.a)