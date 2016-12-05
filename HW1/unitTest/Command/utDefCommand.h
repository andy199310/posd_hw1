//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTDEFCOMMAND_H
#define POSD_HW1_UTDEFCOMMAND_H

#include "../../Execption/NameNotFoundException.h"
#include "../../Execption/ArgumentMismatchException.h"
#include "../../Command/DefCommand.h"
#include "../../Application.h"
#include "../../../cppunitlite/TestHarness.h"

TEST(lengthMismatch, DefCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    try{
        defCommand.execute("def no more");
        FAIL("Should not be here");
    }catch(ArgumentMismatchException){
        CHECK(true);
    }
}

TEST(addBasicCircle, DefCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    try{
        defCommand.execute("def name = Circle(0,0,10)");
        if(application->getMediaByName("name") != nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
    }catch(ArgumentMismatchException){
        FAIL("Should not be here");
    }
}

TEST(addBasicRectangle, DefCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    try{
        defCommand.execute("def name = Rectangle(0,0,10,10)");
        if(application->getMediaByName("name") != nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
    }catch(ArgumentMismatchException){
        FAIL("Should not be here");
    }
}

TEST(addBasicTriangle, DefCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    try{
        defCommand.execute("def name = Triangle(0,0,10,10,2,3)");
        if(application->getMediaByName("name") != nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
    }catch(ArgumentMismatchException){
        FAIL("Should not be here");
    }
}

TEST(addComboNotFound, DefCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    try{
        defCommand.execute("def combo = combo{circle,triangle}");
        FAIL("Should not be here");
    }catch(NameNotFoundException){
        CHECK(true);
    }
}


TEST(addComboMedia, DefCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    try{
        defCommand.execute("def circle = Circle(0,0,10,10,2,3)");
        defCommand.execute("def triangle = Triangle(0,0,10,10,2,3)");
        defCommand.execute("def combo = combo{circle,triangle}");
        if(application->getMediaByName("combo") != nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

#endif //POSD_HW1_UTDEFCOMMAND_H
