//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_UTDELETECOMMAND_H
#define POSD_HW1_UTDELETECOMMAND_H

#include "../../Execption/NameNotFoundException.h"
#include "../../Execption/ArgumentMismatchException.h"
#include "../../Command/AreaCommand.h"
#include "../../Command/ShowCommand.h"
#include "../../Command/DefCommand.h"
#include "../../Command/DeleteCommand.h"
#include "../../AreaVisitor.h"
#include "../../Application.h"
#include "../../../cppunitlite/TestHarness.h"

TEST(deleteFromCombo, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand.execute("delete rectangle1 from combo");
        AreaVisitor areaVisitor;
        Media* media = application->getMediaByName("combo");
        media->accept(&areaVisitor);
        CHECK(areaVisitor.getTotalArea() == 50);

        if(application->getMediaByName("rectangle1") != nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

TEST(deleteAll, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand(application);
    ShowCommand showCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand.execute("delete rectangle1");
        AreaVisitor areaVisitor;
        Media* media = application->getMediaByName("combo");
        media->accept(&areaVisitor);
        CHECK(areaVisitor.getTotalArea() == 50);

        CHECK(application->getMediaMap().size() == 2);

        if(application->getMediaByName("rectangle1") == nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
        showCommand.execute("");
        CHECK(application->getNextOutputString() == "rectangle2")
        CHECK(application->getNextOutputString() == "combo")
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

TEST(deleteCombo, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand.execute("delete combo");

        Media* media = application->getMediaByName("combo");

        CHECK(media == nullptr);

    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

TEST(deleteComboUndo, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand.execute("delete combo");
        deleteCommand.undo();

        Media* media = application->getMediaByName("combo");

        CHECK(media != nullptr);
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}
TEST(deleteComboRedo, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand.execute("delete combo");
        deleteCommand.undo();
        deleteCommand.redo();

        Media* media = application->getMediaByName("combo");

        CHECK(media == nullptr);
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}


TEST(deleteFromComboUndo, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand1(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand1.execute("delete rectangle1 from combo");
        deleteCommand1.undo();
        AreaVisitor areaVisitor;
        Media* media = application->getMediaByName("combo");
        media->accept(&areaVisitor);
        CHECK(areaVisitor.getTotalArea() == 150);

        if(application->getMediaByName("rectangle1") != nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

TEST(deleteFromComboRedo, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand1(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand1.execute("delete rectangle1 from combo");
        deleteCommand1.undo();
        deleteCommand1.redo();
        AreaVisitor areaVisitor;
        Media* media = application->getMediaByName("combo");
        media->accept(&areaVisitor);
        CHECK(areaVisitor.getTotalArea() == 50);

        if(application->getMediaByName("rectangle1") != nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

TEST(deleteAllUndo, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand(application);
    ShowCommand showCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand.execute("delete rectangle1");
        deleteCommand.undo();
        AreaVisitor areaVisitor;
        Media* media = application->getMediaByName("combo");
        media->accept(&areaVisitor);
        CHECK(areaVisitor.getTotalArea() == 150);

        CHECK(application->getMediaMap().size() == 3);

        if(application->getMediaByName("rectangle1") != nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
        showCommand.execute("");
        CHECK(application->getNextOutputString() == "rectangle2")
        CHECK(application->getNextOutputString() == "combo")
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

TEST(deleteAllRedo, AreaCommand){
    Application* application = new Application();
    DefCommand defCommand(application);
    DeleteCommand deleteCommand(application);
    ShowCommand showCommand(application);
    try{
        defCommand.execute("def rectangle1 = Rectangle(0,0,10,10)");
        application->getNextOutputString();
        defCommand.execute("def rectangle2 = Rectangle(0,0,10,5)");
        application->getNextOutputString();
        defCommand.execute("def combo = combo{rectangle1,rectangle2}");
        application->getNextOutputString();
        deleteCommand.execute("delete rectangle1");
        deleteCommand.undo();
        deleteCommand.redo();
        AreaVisitor areaVisitor;
        Media* media = application->getMediaByName("combo");
        media->accept(&areaVisitor);
        CHECK(areaVisitor.getTotalArea() == 50);

        CHECK(application->getMediaMap().size() == 2);

        if(application->getMediaByName("rectangle1") == nullptr){
            CHECK(true);
        }else{
            FAIL("Should not be here");
        }
        showCommand.execute("");
        CHECK(application->getNextOutputString() == "rectangle2")
        CHECK(application->getNextOutputString() == "combo")
    }catch(NameNotFoundException){
        FAIL("Should not be here");
    }
}

#endif //POSD_HW1_UTDELETECOMMAND_H
