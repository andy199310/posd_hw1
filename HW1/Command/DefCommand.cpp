//
// Created by Green on 2016/12/5.
//

#include <iostream>
#include <string>
#include <HW1/CompositeMedia.h>

#include "DefCommand.h"
#include "CommandFunction.h"
#include "HW1/Execption/ArgumentMismatchException.h"
#include "HW1/Execption/NameDuplicateException.h"
#include "HW1/Execption/NameNotFoundException.h"
#include "../ShapeMedia.h"
#include "../Circle.h"
#include "../Rectangle.h"
#include "../Triangle.h"

DefCommand::DefCommand(Application *application):_application(application){

}

void DefCommand::execute(std::string command) {
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

        std::string key = argumentList.at(1).substr(0, argumentList.at(1).length()-1);
        _application->addMedia(key, compositeMedia);

        return;
    }else{
        if(CommandFunction::startWith(argumentList.at(3), "Circle")){
            std::vector<double> itemVector;
            CommandFunction::getShapeArgumentFromString(&itemVector, argumentList.at(3));
            std::string key = argumentList.at(1).substr(0, argumentList.at(1).length()-1);
            _application->addMedia(key, new ShapeMedia(new Circle(itemVector.at(0), itemVector.at(1), itemVector.at(2))));

            return;
        }
        if(CommandFunction::startWith(argumentList.at(3), "Rectangle")){
            std::vector<double> itemVector;
            CommandFunction::getShapeArgumentFromString(&itemVector, argumentList.at(3));
            std::string key = argumentList.at(1).substr(0, argumentList.at(1).length()-1);
            _application->addMedia(key, new ShapeMedia(new Rectangle(itemVector.at(0), itemVector.at(1), itemVector.at(2), itemVector.at(3))));

            return;
        }
        if(CommandFunction::startWith(argumentList.at(3), "Triangle")){
            std::vector<double> itemVector;
            CommandFunction::getShapeArgumentFromString(&itemVector, argumentList.at(3));
            std::string key = argumentList.at(1).substr(0, argumentList.at(1).length()-1);
            _application->addMedia(key, new ShapeMedia(new Triangle(itemVector.at(0), itemVector.at(1), itemVector.at(2), itemVector.at(3), itemVector.at(4), itemVector.at(5))));

            return;
        }
    }
}
