//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTPERIMETERCOMMAND_H
#define POSD_HW1_UTPERIMETERCOMMAND_H


#include "../../Execption/NameNotFoundException.h"
#include "../../Execption/ArgumentMismatchException.h"
#include "../../Command/PerimeterCommand.h"
#include "../../Command/DefCommand.h"
#include "../../Application.h"
#include "../../../cppunitlite/TestHarness.h"

TEST(lengthMismatch, PerimeterCommand){
    Application* application = new Application();
    PerimeterCommand perimeterCommand(application);
    try{
        perimeterCommand.execute("no dot");
        FAIL("Should not be here");
    }catch(ArgumentMismatchException){
        CHECK(true);
    }
}

TEST(nameNotFound, PerimeterCommand){
    Application* application = new Application();
    PerimeterCommand perimeterCommand(application);
    try{
        perimeterCommand.execute("no.perimeter?");
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        CHECK(true);
    }
}

TEST(basic, PerimeterCommand){
    Application* application = new Application();
    PerimeterCommand perimeterCommand(application);
    DefCommand defCommand(application);
    try{
        defCommand.execute("def rectangle = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        perimeterCommand.execute("rectangle.perimeter?");
        CHECK(application->getNextOutputString() == "40");
    }catch(ArgumentMismatchException){
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

TEST(combo, PerimeterCommand){
    Application* application = new Application();
    PerimeterCommand perimeterCommand(application);
    DefCommand defCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        perimeterCommand.execute("combo.perimeter?");
        CHECK(application->getNextOutputString() == "70");
    }catch(ArgumentMismatchException){
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

#endif //POSD_HW1_UTPERIMETERCOMMAND_H
