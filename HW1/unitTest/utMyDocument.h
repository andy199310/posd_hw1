//
// Created by Green on 2016/11/21.
//

#ifndef POSD_HW1_UTMYDOCUMENT_H
#define POSD_HW1_UTMYDOCUMENT_H

#define EPSILON 0.001

#include "../../cppunitlite/TestHarness.h"
#include "../MyDocument.h"

TEST(wrongName, MyDocument){
    MyDocument myDocument;
    try{
        std::string result = myDocument.openDocument("404.txt");
        FAIL("Cannot be here!");
    }catch(std::string message){
        CHECK(message == "File is not existed.");
    }
}

TEST(correctName, MyDocument){
    MyDocument myDocument;
    try{
        std::string result = myDocument.openDocument("myShape.txt");
        CHECK(result == "combo(r(0 0 3 2) c(0 0 5) combo(r(0 0 5 4) c(0 0 10) )combo(r(0 1 8 7) c(0 1 10) ))")
    }catch(std::string message){
        FAIL("Cannot be here!");
    }
}

#endif //POSD_HW1_UTMYDOCUMENT_H
