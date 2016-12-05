//
// Created by Green on 2016/12/5.
//

#include "PerimeterCommand.h"
#include "CommandFunction.h"
#include "../Execption/NameNotFoundException.h"
#include <sstream>
#include "../PerimeterVisitor.h"
#include "../Execption/ArgumentMismatchException.h"

PerimeterCommand::PerimeterCommand(Application *application):_application(application) {

}

void PerimeterCommand::execute(std::string command) {
    std::vector<std::string> argumentVector;
    CommandFunction::split(command, argumentVector, '.');

    if(argumentVector.size() != 2){
        throw ArgumentMismatchException();
    }

    Media *media = _application->getMediaByName(argumentVector.at(0));
    if(media == nullptr){
        throw NameNotFoundException(argumentVector.at(0));
    }

    PerimeterVisitor perimeterVisitor;
    media->accept(&perimeterVisitor);

    std::stringstream stream;
    stream << perimeterVisitor.getTotalPerimeter();
    _application->writeOutput(stream.str());
}

bool PerimeterCommand::checkValid(std::string command) {
    return CommandFunction::endWith(command, "perimeter?");
}
