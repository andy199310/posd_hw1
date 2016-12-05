//
// Created by Green on 2016/12/5.
//


#include <iostream>
#include "Command/CommandFunction.h"
#include "Shell.h"
#include "Command/AddCommand.h"
#include "Command/AreaCommand.h"
#include "Command/DefCommand.h"
#include "Command/DeleteCommand.h"
#include "Command/PerimeterCommand.h"
#include "Command/ShowCommand.h"

Shell::Shell(Application *application):_application(application) {
    _commandMap.push_back(new AddCommand(_application));
    _commandMap.push_back(new AreaCommand(_application));
    _commandMap.push_back(new DefCommand(_application));
    _commandMap.push_back(new DeleteCommand(_application));
    _commandMap.push_back(new PerimeterCommand(_application));
    _commandMap.push_back(new ShowCommand(_application));
}

void Shell::runCommand(std::string command) {
    for(unsigned int i=0; i<_commandMap.size(); i++){
        if(_commandMap.at(i)->checkValid(command)){
            _commandMap.at(i)->execute(command);
            printOutput();
            return;
        }
    }
    std::cout << "Command not found!" << std::endl;
}

void Shell::printOutput() {
    std::string tmpString = _application->getNextOutputString();
    while(tmpString.length() > 0){
        std::cout << ">> " <<  tmpString << std::endl;
        tmpString = _application->getNextOutputString();
    }
}

void Shell::start() {
    std::string command;
    std::cout << ":- ";
    while(std::getline(std::cin, command)){

        this->runCommand(command);
        std::cout << ":- ";
    }
}
