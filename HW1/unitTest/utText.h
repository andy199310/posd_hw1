//
// Created by Green on 2016/10/28.
//

#ifndef POSD_HW1_UTTEXT_H
#define POSD_HW1_UTTEXT_H

#define EPSILON 0.001

#include "../Text.h"
#include "../../cppunitlite/TestHarness.h"

TEST(basic, Text){
    Rectangle boundingBox(0, 0, 5, 10);
    Text text(boundingBox, "Hello World!");

    CHECK("Hello World!" == text.getText());

    Rectangle testBoundingBox = text.getBoundingBox();

    DOUBLES_EQUAL(boundingBox.area(), testBoundingBox.area(), EPSILON)
}

#endif //POSD_HW1_UTTEXT_H
