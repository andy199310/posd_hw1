#include <iostream>

#include "../cppunitlite/TestHarness.h"

#include "unitTest/utMain.h"
#include "Text.h"
#include "TextMedia.h"
#include "AreaVisitor.h"

int main(){
//    TestResult tr;
//    TestRegistry::runAllTests(tr);

    Rectangle rectangle(0, 0, 1, 1);

    ShapeMedia shapeMedia;
    shapeMedia.add(&rectangle);

    CompositeMedia compositeMedia;
    compositeMedia.add(&shapeMedia);


    Text text;
    TextMedia textMedia;
    textMedia.add(&text);

    AreaVisitor areaVisitor;

//    compositeMedia.add(&textMedia);

    return 0;
}
