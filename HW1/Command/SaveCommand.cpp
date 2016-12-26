//
// Created by Green on 2016/12/5.
//

#include "../Execption/ArgumentMismatchException.h"
#include "SaveCommand.h"
#include "CommandFunction.h"
#include <iostream>
#include <fstream>
#include "../DescriptionNameVisitor.h"
#include "../DescriptionVisitor.h"
#include "../Execption/NameNotFoundException.h"

SaveCommand::SaveCommand(Application *application):_application(application){

}

void SaveCommand::execute(std::string command) {
    std::vector<std::string> argumentVector;
    CommandFunction::split(command, argumentVector, ' ');

    if(argumentVector.size() != 4){
        throw ArgumentMismatchException();
    }

    Media *media = _application->getMediaByName(argumentVector.at(1));
    if(media == nullptr){
        throw NameNotFoundException(argumentVector.at(1));
    }
    std::string mediaName = argumentVector.at(1);
    DescriptionVisitor descriptionVisitor;
    media->accept(&descriptionVisitor);
    std::string descriptionString = descriptionVisitor.getDescription();

    DescriptionNameVisitor descriptionNameVisitor(_application);
    media->accept(&descriptionNameVisitor);
    std::string descriptionNameString = descriptionNameVisitor.getDescription();

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
        file << descriptionString << "\n";
        file << descriptionNameString << "\n";
        file.close();
    }
    _application->writeOutput(mediaName + " saved to " + tmpFileName);
}

bool SaveCommand::checkValid(std::string command) {
    return CommandFunction::startWith(command, "save ");
}

bool SaveCommand::needUndo() {
    return false;
}

void SaveCommand::undo() {

}

void SaveCommand::redo() {

}

Command *SaveCommand::clone() {
    return nullptr;
}
