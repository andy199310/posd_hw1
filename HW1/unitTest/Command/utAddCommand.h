//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTADDCOMMAND_H
#define POSD_HW1_UTADDCOMMAND_H


#include "../../Execption/NameNotFoundException.h"
#include "../../Execption/ArgumentMismatchException.h"
#include "../../Command/DefCommand.h"
#include "../../Command/AreaCommand.h"
#include "../../Command/AddCommand.h"
#include "../../Application.h"
#include "../../../cppunitlite/TestHarness.h"

TEST(lengthMismatch, AddCommand){
    Application* application = new Application();
    AddCommand addCommand(application);
    try{
        addCommand.execute("no more");
        FAIL("Should not be here");
    }catch(ArgumentMismatchException){
        CHECK(true);
    }
}

TEST(nameNotFoundChild, AddCommand){
    Application* application = new Application();
    AddCommand addCommand(application);
    try{
        addCommand.execute("add rectangle to combo");
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        CHECK(true);
    }
}

TEST(nameNotFoundTarget, AddCommand){
    Application* application = new Application();
    AddCommand addCommand(application);
    DefCommand defCommand(application);
    try{
        defCommand.execute("def rectangle = Rectangle(0,0,10,10)");
        addCommand.execute("add rectangle to combo");
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        CHECK(true);
    }
}

TEST(basic, AddCommand){
    Application* application = new Application();
    AddCommand addCommand(application);
    DefCommand defCommand(application);
    try{
        defCommand.execute("def rectangle = Rectangle(0,0,10,10)");
        defCommand.execute("def combo = combo{}");
        addCommand.execute("add rectangle to combo");
        
        AreaVisitor areaVisitor;
        Media* media = application->getMediaByName("combo");
        media->accept(&areaVisitor);

        CHECK(areaVisitor.getTotalArea() == 100)
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

#endif //POSD_HW1_UTADDCOMMAND_H
