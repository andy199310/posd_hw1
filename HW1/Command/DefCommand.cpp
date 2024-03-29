//
// Created by Green on 2016/12/5.
//

#include <iostream>
#include <string>


#include "DefCommand.h"
#include "CommandFunction.h"
#include "../Execption/ArgumentMismatchException.h"
#include "../Execption/NameDuplicateException.h"
#include "../Execption/NameNotFoundException.h"
#include "../Execption/NameNotFoundException.h"
#include "../CompositeMedia.h"
#include "../ShapeMedia.h"
#include "../Circle.h"
#include "../Rectangle.h"
#include "../Triangle.h"

DefCommand::DefCommand(Application *application):_application(application){

}

void DefCommand::execute(std::string command) {
    _command = command;
    std::vector<std::string> argumentList;
    CommandFunction::split(command, argumentList, ' ');
    if(argumentList.size() != 4){
        throw ArgumentMismatchException();
    }

    //check name duplicate
    if(_application->getMediaByName(argumentList.at(1)) != nullptr){
        throw NameDuplicateException();
    }

    if(CommandFunction::startWith(argumentList.at(3), "combo")){
        std::vector<std::string> itemVector;
        CommandFunction::getComboArgumentFromString(&itemVector, argumentList.at(3));
        CompositeMedia *compositeMedia = new CompositeMedia();
        for(unsigned int i=0; i<itemVector.size(); i++){
            std::string key = itemVector.at(i);
            Media *media = _application->getMediaByName(key);
            if(media == nullptr){
                throw NameNotFoundException(key);
            }
            compositeMedia->add(media);
        }

        std::string key = argumentList.at(1).substr(0, argumentList.at(1).length());
        _key = key;
        _application->addMedia(key, compositeMedia);
        _application->writeOutput(argumentList.at(3));
        return;
    }else{
        if(CommandFunction::startWith(argumentList.at(3), "Circle")){
            std::vector<double> itemVector;
            CommandFunction::getShapeArgumentFromString(&itemVector, argumentList.at(3));
            std::string key = argumentList.at(1).substr(0, argumentList.at(1).length());
            _key = key;
            _application->addMedia(key, new ShapeMedia(new Circle(itemVector.at(0), itemVector.at(1), itemVector.at(2))));
            _application->writeOutput(argumentList.at(3));
            return;
        }
        if(CommandFunction::startWith(argumentList.at(3), "Rectangle")){
            std::vector<double> itemVector;
            CommandFunction::getShapeArgumentFromString(&itemVector, argumentList.at(3));
            std::string key = argumentList.at(1).substr(0, argumentList.at(1).length());
            _key = key;
            _application->addMedia(key, new ShapeMedia(new Rectangle(itemVector.at(0), itemVector.at(1), itemVector.at(2), itemVector.at(3))));
            _application->writeOutput(argumentList.at(3));
            return;
        }
        if(CommandFunction::startWith(argumentList.at(3), "Triangle")){
            std::vector<double> itemVector;
            CommandFunction::getShapeArgumentFromString(&itemVector, argumentList.at(3));
            std::string key = argumentList.at(1).substr(0, argumentList.at(1).length());
            _key = key;
            _application->addMedia(key, new ShapeMedia(new Triangle(itemVector.at(0), itemVector.at(1), itemVector.at(2), itemVector.at(3), itemVector.at(4), itemVector.at(5))));
            _application->writeOutput(argumentList.at(3));
            return;
        }
    }
}

bool DefCommand::checkValid(std::string command) {
    return CommandFunction::startWith(command, "def ");
}

void DefCommand::undo() {
    _application->deleteMedia(_key);
}

Command *DefCommand::clone() {
    return new DefCommand(_application);
}

bool DefCommand::needUndo() {
    return true;
}

void DefCommand::redo() {
    this->execute(_command);
}
