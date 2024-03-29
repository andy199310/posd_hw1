//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_SHELL_H
#define POSD_HW1_SHELL_H


#include <stack>
#include "Command/Command.h"
#include "Application.h"

class Shell {
private:
    Application *_application;
    std::vector<Command*> _commandMap;
public:
    std::stack<Command*> _commandHistory;
    std::stack<Command*> _undoCommandHistory;
public:
    void runCommand(std::string command);
    void undo();
    void redo();
    void start();
private:
    void printOutput();

public:
    Shell(Application* application);


};


#endif //POSD_HW1_SHELL_H
