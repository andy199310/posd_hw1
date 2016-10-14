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
        HW1/unitTest/utTriangle.h HW1/unitTest/utMain.h HW1/CompositeMedia.cpp HW1/CompositeMedia.h HW1/unitTest/utCompositeShape.h HW1/Media.cpp HW1/Media.h HW1/ShapeMedia.cpp HW1/ShapeMedia.h HW1/TextMedia.cpp HW1/TextMedia.h HW1/Text.cpp HW1/Text.h HW1/MediaVisitor.h HW1/AreaVisitor.cpp HW1/AreaVisitor.h HW1/PerimeterVisitor.cpp HW1/PerimeterVisitor.h HW1/unitTest/utAreaVisitor.h HW1/unitTest/utPerimeterVisitor.h)

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")

add_executable(posd_hw1 ${SOURCE_FILES})

# for CMake to build libCppUnitLite.a file (PS: need to dig into cache folder for lib)
# add_library(libCppUnitLite cppunitlite/Failure.cpp cppunitlite/Failure.h cppunitlite/SimpleString.h cppunitlite/SimpleString.cpp cppunitlite/Test.h cppunitlite/Test.cpp cppunitlite/TestResult.h cppunitlite/TestRegistry.cpp cppunitlite/TestResult.cpp cppunitlite/TestRegistry.h)

target_link_libraries(posd_hw1 ${CMAKE_SOURCE_DIR}/cppunitlite/libCppUnitLite.a)