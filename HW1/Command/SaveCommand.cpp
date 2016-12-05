//
// Created by Green on 2016/12/5.
//

#include "../Execption/ArgumentMismatchException.h"
#include "SaveCommand.h"
#include "CommandFunction.h"
#include <iostream>
#include <fstream>

SaveCommand::SaveCommand(Shell *shell):_shell(shell){

}

void SaveCommand::execute(std::string command) {
    std::vector<std::string> argumentVector;
    CommandFunction::split(command, argumentVector, ' ');

    if(argumentVector.size() != 4){
        throw ArgumentMismatchException();
    }
    std::string tmpFileName = argumentVector.at(3);
    argumentVector.clear();
    CommandFunction::split(tmpFileName, argumentVector, '"');
    if(argumentVector.size() <= 0){
        throw ArgumentMismatchException();
    }
    tmpFileName = argumentVector.at(argumentVector.size()-1);
    std::ofstream file(tmpFileName);
    if (file.is_open())
    {
        for(unsigned int i=0; i<_shell->_commandHistory.size(); i++){
            file << _shell->_commandHistory.at(i) << "\n";
        }
        file.close();
    }
}

bool SaveCommand::checkValid(std::string command) {
    return CommandFunction::startWith(command, "save ");
}
