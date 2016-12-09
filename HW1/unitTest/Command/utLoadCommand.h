//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTLOADCOMMAND_H
#define POSD_HW1_UTLOADCOMMAND_H

#include <iostream>
#include "../../Command/LoadCommand.h"
#include "../../Command/AreaCommand.h"
#include "../../Application.h"
#include "../../../cppunitlite/TestHarness.h"
#include "../../Execption/NameNotFoundException.h"

TEST(basic, SaveCommand){
    Application* application = new Application();
    LoadCommand loadCommand(application);
    AreaCommand areaCommand(application);
    try{
        loadCommand.execute("load \"myShapes.txt\"");
        application->getNextOutputString();
        areaCommand.execute("comboExclamation.area?");

        CHECK(application->getNextOutputString() == "19")
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}
#endif //POSD_HW1_UTLOADCOMMAND_H
