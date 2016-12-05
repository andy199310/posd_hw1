//
// Created by Green on 2016/12/5.
//

#include <vector>
#include "../Execption/NameNotFoundException.h"
#include "../AreaVisitor.h"
#include <iostream>
#include <cstdio>
#include <sstream>
#include "../Execption/ArgumentMismatchException.h"
#include "AreaCommand.h"
#include "CommandFunction.h"

AreaCommand::AreaCommand(Application *application):_application(application) {

}

void AreaCommand::execute(std::string command) {
    std::vector<std::string> argumentVector;
    CommandFunction::split(command, argumentVector, '.');

    if(argumentVector.size() != 2){
        throw ArgumentMismatchException();
    }

    Media *media = _application->getMediaByName(argumentVector.at(0));
    if(media == nullptr){
        throw NameNotFoundException(argumentVector.at(0));
    }

    AreaVisitor areaVisitor;
    media->accept(&areaVisitor);

    std::stringstream stream;
    stream << areaVisitor.getTotalArea();
    _application->writeOutput(stream.str());
}

bool AreaCommand::checkValid(std::string command) {
    return CommandFunction::endWith(command, "area?");
}
