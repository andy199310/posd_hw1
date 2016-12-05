//
// Created by Green on 2016/12/5.
//


#include <iostream>
#include "Execption/ArgumentMismatchException.h"
#include "Execption/NameNotFoundException.h"
#include "Execption/NameDuplicateException.h"


#include "Shell.h"
#include "Command/CommandFunction.h"
#include "Command/AddCommand.h"
#include "Command/AreaCommand.h"
#include "Command/DefCommand.h"
#include "Command/DeleteCommand.h"
#include "Command/PerimeterCommand.h"
#include "Command/ShowCommand.h"
#include "Command/SaveCommand.h"

Shell::Shell(Application *application):_application(application) {
    _commandMap.push_back(new AddCommand(_application));
    _commandMap.push_back(new AreaCommand(_application));
    _commandMap.push_back(new DefCommand(_application));
    _commandMap.push_back(new DeleteCommand(_application));
    _commandMap.push_back(new PerimeterCommand(_application));
    _commandMap.push_back(new ShowCommand(_application));
    _commandMap.push_back(new SaveCommand(this));
}

void Shell::runCommand(std::string command) {
    for(unsigned int i=0; i<_commandMap.size(); i++){
        if(_commandMap.at(i)->checkValid(command)){
            try{
                _commandMap.at(i)->execute(command);
            }catch (ArgumentMismatchException){
                std::cout << "Argument mismatch. Please check your command." << std::endl;
                return;
            }catch (NameNotFoundException){
                std::cout << "Name not found. Please check your command." << std::endl;
                return;
            }catch (NameDuplicateException){
                std::cout << "Name duplicate. Please check your command." << std::endl;
                return;
            }catch(...){
                std::cout << "There is some unexpected error. Please check your command." << std::endl;
            }
            _commandHistory.push_back(command);
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
