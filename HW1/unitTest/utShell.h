//
// Created by Green on 2016/12/26.
//

#ifndef POSD_HW1_UTSHELL_H
#define POSD_HW1_UTSHELL_H

#define EPSILON 0.001

#include "../CompositeMedia.h"
#include "../Application.h"
#include "../Shell.h"
#include "../../cppunitlite/TestHarness.h"

TEST(noThingToUndo, Shell){
    Application application;
    Shell shell(&application);
    shell.undo();
    CHECK(application.getNextOutputString() == "No command to undo!");
}

TEST(Undo1, Shell){
    Application application;
    Shell shell(&application);
    shell.runCommand("def c = Circle(0,0,10)");
    shell.runCommand("def c1 = Circle(0,0,10)");
    while(application.getNextOutputString().length() > 0){}
    shell.undo();
    CHECK(application.getNextOutputString() == "Undo command!");
    CHECK(application.getMediaByName("c") != nullptr);
    CHECK(application.getMediaByName("c1") == nullptr);
}

TEST(Undo2, Shell){
    Application application;
    Shell shell(&application);
    shell.runCommand("def c = Circle(0,0,10)");
    shell.runCommand("def c1 = Circle(0,0,10)");
    while(application.getNextOutputString().length() > 0){}
    shell.undo();
    shell.undo();
    CHECK(application.getNextOutputString() == "Undo command!");
    CHECK(application.getMediaByName("c") == nullptr);
    CHECK(application.getMediaByName("c1") == nullptr);
}

TEST(noThingToRedo, Shell){
    Application application;
    Shell shell(&application);
    shell.redo();
    CHECK(application.getNextOutputString() == "No command to redo!");
}

TEST(Redo1, Shell){
    Application application;
    Shell shell(&application);
    shell.runCommand("def c = Circle(0,0,10)");
    shell.runCommand("def c1 = Circle(0,0,10)");
    shell.undo();
    while(application.getNextOutputString().length() > 0){}
    shell.redo();
    CHECK(application.getNextOutputString() == "Circle(0,0,10)");
    CHECK(application.getNextOutputString() == "Redo command!");
    CHECK(application.getMediaByName("c") != nullptr);
    CHECK(application.getMediaByName("c1") != nullptr);
}

TEST(Redo2OverFlow, Shell){
    Application application;
    Shell shell(&application);
    shell.runCommand("def c1 = Circle(0,0,10)");
    shell.undo();
    while(application.getNextOutputString().length() > 0){}
    shell.redo();
    shell.redo();
    CHECK(application.getNextOutputString() == "Circle(0,0,10)");
    CHECK(application.getNextOutputString() == "Redo command!");
    CHECK(application.getNextOutputString() == "No command to redo!");
    CHECK(application.getMediaByName("c1") != nullptr);
}
TEST(Redo2, Shell){
    Application application;
    Shell shell(&application);
    shell.runCommand("def c = Circle(0,0,10)");
    shell.runCommand("def c1 = Circle(0,0,10)");
    shell.undo();
    shell.undo();
    while(application.getNextOutputString().length() > 0){}
    shell.redo();
    CHECK(application.getNextOutputString() == "Circle(0,0,10)");
    CHECK(application.getNextOutputString() == "Redo command!");
    shell.redo();
    CHECK(application.getNextOutputString() == "Circle(0,0,10)");
    CHECK(application.getNextOutputString() == "Redo command!");
    CHECK(application.getMediaByName("c") != nullptr);
    CHECK(application.getMediaByName("c1") != nullptr);
}

#endif //POSD_HW1_UTSHELL_H
