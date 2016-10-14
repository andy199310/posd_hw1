#include <iostream>

#include "../cppunitlite/TestHarness.h"

#include "unitTest/utMain.h"
#include "Text.h"
#include "TextMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"

int main(){
//    TestResult tr;
//    TestRegistry::runAllTests(tr);

    Rectangle rectangle(0, 0, 1, 1);

    ShapeMedia shapeMedia;
    shapeMedia.add(&rectangle);

    Circle circle(0, 0, 10);
    shapeMedia.add(&circle);

    CompositeMedia compositeMedia;
    compositeMedia.add(&shapeMedia);



    Text text;
    TextMedia textMedia;
    textMedia.add(&text);

    AreaVisitor areaVisitor;

    compositeMedia.accept(&areaVisitor);
    std::cout << "TotalArea:" << areaVisitor.getTotalArea() << std::endl;

    PerimeterVisitor perimeterVisitor;

    compositeMedia.accept(&perimeterVisitor);

    std::cout << "TotalPerimeter:" << perimeterVisitor.getTotalPerimeter() << std::endl;
//    compositeMedia.add(&textMedia);

    return 0;
}
