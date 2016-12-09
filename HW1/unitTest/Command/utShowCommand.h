//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTSHOWCOMMAND_H
#define POSD_HW1_UTSHOWCOMMAND_H

#include "../../Command/ShowCommand.h"
#include "../../Command/DefCommand.h"
#include "../../Application.h"
#include "../../../cppunitlite/TestHarness.h"
#include "../../Execption/NameNotFoundException.h"

TEST(basic, ShowCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    ShowCommand showCommand(application);
    try{
        defCommand.execute("def circle = Circle(0,0,10,10,2,3)");
        application->getNextOutputString();
        defCommand.execute("def triangle = Triangle(0,0,10,10,2,3)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{circle,triangle}");
        application->getNextOutputString();
        showCommand.execute("");
        CHECK(application->getNextOutputString() == "circle")
        CHECK(application->getNextOutputString() == "triangle")
        CHECK(application->getNextOutputString() == "combo")
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

#endif //POSD_HW1_UTSHOWCOMMAND_H
