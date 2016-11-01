#include <iostream>
#include "../cppunitlite/TestHarness.h"
#include "unitTest/utMain.h"

int main(){
    TestResult tr;
    TestRegistry::runAllTests(tr);

    try{
//        ShapeMedia *shapeMediaRectangle = new ShapeMedia(new Rectangle(0, 0, 10, 10));
//
//        ShapeMedia *shapeMediaCircle = new ShapeMedia(new Circle(0, 0, 10));
//
//        CompositeMedia compositeMedia;
//        compositeMedia.add(shapeMediaRectangle);
//
//        CompositeMedia compositeMedia2;
//        compositeMedia2.add(shapeMediaCircle);
//        compositeMedia2.add(&compositeMedia);
//
//        std::cout << "Size Before: " << compositeMedia2.size() << std::endl;
//
//        compositeMedia2.remove(shapeMediaRectangle);
//
//        std::cout << "Size After: " << compositeMedia2.size() << std::endl;

    }catch (const char* message){
        std::cout << message << std::endl;
    }


    return 0;
}
