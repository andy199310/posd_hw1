//
// Created by Green on 2016/12/5.
//

#include "../DescriptionVisitor.h"
#include "../DescriptionNameVisitor.h"
#include "../Execption/NameNotFoundException.h"
#include "../Execption/ArgumentMismatchException.h"
#include "AddCommand.h"
#include "CommandFunction.h"
#include "../Application.h"

AddCommand::AddCommand(Application *application):_application(application) {

}

void AddCommand::execute(std::string command) {
    _command = command;
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

    _parentKey = argumentList.at(3);
    _key =  argumentList.at(1);
    target->add(child);

    DescriptionVisitor descriptionVisitor;
    DescriptionNameVisitor descriptionNameVisitor(_application);

    target->accept(&descriptionVisitor);
    target->accept(&descriptionNameVisitor);

    _application->writeOutput(argumentList.at(1) + " = " + descriptionNameVisitor.getDescription() + " = " + descriptionVisitor.getDescription());
}

bool AddCommand::checkValid(std::string command) {
    return CommandFunction::startWith(command, "add ");
}

Command *AddCommand::clone() {
    return new AddCommand(_application);
}

void AddCommand::undo() {
    Media *parent = _application->getMediaByName(_parentKey);
    Media *child = _application->getMediaByName(_key);
    parent->remove(child);
}

bool AddCommand::needUndo() {
    return true;
}

void AddCommand::redo() {
    this->execute(_command);
}
