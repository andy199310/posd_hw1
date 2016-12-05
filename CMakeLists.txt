cmake_minimum_required(VERSION 2.8)
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
        HW1/unitTest/utTriangle.h HW1/unitTest/utMain.h HW1/CompositeMedia.cpp HW1/CompositeMedia.h HW1/unitTest/utCompositeShape.h HW1/Media.cpp HW1/Media.h HW1/ShapeMedia.cpp HW1/ShapeMedia.h HW1/TextMedia.cpp HW1/TextMedia.h HW1/Text.cpp HW1/Text.h HW1/MediaVisitor.h HW1/AreaVisitor.cpp HW1/AreaVisitor.h HW1/PerimeterVisitor.cpp HW1/PerimeterVisitor.h HW1/unitTest/utAreaVisitor.h HW1/unitTest/utPerimeterVisitor.h HW1/DescriptionVisitor.cpp HW1/DescriptionVisitor.h HW1/unitTest/utDescriptionVisitor.h HW1/CountingVisitor.cpp HW1/CountingVisitor.h HW1/MediaBuilder.cpp HW1/MediaBuilder.h HW1/unitTest/utMediaBuilder.h HW1/unitTest/utText.h HW1/Document.h HW1/MyDocument.cpp HW1/MyDocument.h HW1/unitTest/utMyDocument.h HW1/MediaDirector.cpp HW1/MediaDirector.h HW1/unitTest/utMediaDirector.h HW1/Application.cpp HW1/Application.h HW1/Command/Command.h HW1/Command/DefCommand.cpp HW1/Command/DefCommand.h HW1/Command/CommandFunction.cpp HW1/Command/CommandFunction.h HW1/Execption/ArgumentMismatchException.cpp HW1/Execption/ArgumentMismatchException.h HW1/unitTest/utApplication.h HW1/unitTest/Command/utDefCommand.h HW1/Execption/NameDuplicateException.cpp HW1/Execption/NameDuplicateException.h HW1/Execption/NameNotFoundException.cpp HW1/Execption/NameNotFoundException.h HW1/Command/AreaCommand.cpp HW1/Command/AreaCommand.h HW1/unitTest/Command/utAreaCommand.h)

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")

configure_file(HW1/myShape.txt myShape.txt COPYONLY)

add_executable(posd_hw1 ${SOURCE_FILES})

if(DEFINED ENV{TRAVIS})
    add_library(libCppUnitLite cppunitlite/Failure.cpp cppunitlite/Failure.h cppunitlite/SimpleString.h cppunitlite/SimpleString.cpp cppunitlite/Test.h cppunitlite/Test.cpp cppunitlite/TestResult.h cppunitlite/TestRegistry.cpp cppunitlite/TestResult.cpp cppunitlite/TestRegistry.h)
    target_link_libraries(posd_hw1 libCppUnitLite)
else()
    target_link_libraries(posd_hw1 ${CMAKE_SOURCE_DIR}/cppunitlite/libCppUnitLite.a)
endif()
# for CMake to build libCppUnitLite.a file (PS: need to dig into cache folder for lib)
# add_library(libCppUnitLite cppunitlite/Failure.cpp cppunitlite/Failure.h cppunitlite/SimpleString.h cppunitlite/SimpleString.cpp cppunitlite/Test.h cppunitlite/Test.cpp cppunitlite/TestResult.h cppunitlite/TestRegistry.cpp cppunitlite/TestResult.cpp cppunitlite/TestRegistry.h)

