//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTAREACOMMAND_H
#define POSD_HW1_UTAREACOMMAND_H

#include "../../Execption/NameNotFoundException.h"
#include "../../Execption/ArgumentMismatchException.h"
#include "../../Command/AreaCommand.h"
#include "../../Application.h"
#include "../../../cppunitlite/TestHarness.h"

TEST(lengthMismatch, AreaCommand){
    Application* application = new Application();
    AreaCommand areaCommand(application);
    try{
        areaCommand.execute("no dot");
        FAIL("Should not be here");
    }catch(ArgumentMismatchException){
        CHECK(true);
    }
}

TEST(nameNotFound, AreaCommand){
    Application* application = new Application();
    AreaCommand areaCommand(application);
    try{
        areaCommand.execute("no.area?");
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        CHECK(true);
    }
}

TEST(basic, AreaCommand){
    Application* application = new Application();
    AreaCommand areaCommand(application);
    DefCommand defCommand(application);
    try{
        defCommand.execute("def rectangle = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        areaCommand.execute("rectangle.area?");
        CHECK(application->getNextOutputString() == "100");
    }catch(ArgumentMismatchException){
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

TEST(combo, AreaCommand){
    Application* application = new Application();
    AreaCommand areaCommand(application);
    DefCommand defCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        areaCommand.execute("combo.area?");
        CHECK(application->getNextOutputString() == "150");
    }catch(ArgumentMismatchException){
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

#endif //POSD_HW1_UTAREACOMMAND_H
