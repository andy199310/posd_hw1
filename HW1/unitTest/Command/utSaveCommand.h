//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTSAVECOMMAND_H
#define POSD_HW1_UTSAVECOMMAND_H


#include <iostream>
#include "../../Command/SaveCommand.h"
#include "../../Command/DefCommand.h"
#include "../../Application.h"
#include "../../../cppunitlite/TestHarness.h"
#include "../../Execption/NameNotFoundException.h"

TEST(basic, LoadCommand){
    Application* application = new Application();
    SaveCommand saveCommand(application);
    DefCommand defCommand(application);
    try{
        defCommand.execute("def rTall = Rectangle(1,10,2,8)");
        defCommand.execute("def cSmall = Circle(2,1,1)");
        defCommand.execute("def comboExclamation = combo{rTall,cSmall}");
        saveCommand.execute("save comboExclamation to \"myShapes2.txt\"");

    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

#endif //POSD_HW1_UTSAVECOMMAND_H
