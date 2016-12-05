//
// Created by Green on 2016/12/5.
//

#include "../Execption/NameNotFoundException.h"
#include "../Execption/ArgumentMismatchException.h"
#include "AddCommand.h"
#include "CommandFunction.h"

AddCommand::AddCommand(Application *application):_application(application) {

}

void AddCommand::execute(std::string command) {
    std::vector<std::string> argumentList;
    CommandFunction::split(command, argumentList, ' ');
    if(argumentList.size() != 4){
        throw ArgumentMismatchException();
    }

    Media* child = _application->getMediaByName(argumentList.at(1));
    if(child == nullptr){
        throw NameNotFoundException(argumentList.at(1));
    }
    Media* target = _application->getMediaByName(argumentList.at(3));
    if(target == nullptr){
        throw NameNotFoundException(argumentList.at(3));
    }

    target->add(child);
}

bool AddCommand::checkValid(std::string command) {
    return CommandFunction::startWith(command, "add ");
}
