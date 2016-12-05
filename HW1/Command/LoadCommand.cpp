//
// Created by Green on 2016/12/5.
//

#include "../Execption/ArgumentMismatchException.h"
#include "LoadCommand.h"
#include "CommandFunction.h"
#include <iostream>
#include <fstream>
#include <HW1/MediaDirector.h>
#include <HW1/CompositeMedia.h>
#include "../MediaBuilder.h"

LoadCommand::LoadCommand(Application *application):_application(application) {

}

void LoadCommand::execute(std::string command) {
    std::vector<std::string> argumentVector;
    CommandFunction::split(command, argumentVector, ' ');

    if(argumentVector.size() != 2){
        throw ArgumentMismatchException();
    }

    std::string tmpFileName = argumentVector.at(1);
    argumentVector.clear();
    CommandFunction::split(tmpFileName, argumentVector, '"');
    if(argumentVector.size() <= 0){
        throw ArgumentMismatchException();
    }
    tmpFileName = argumentVector.at(argumentVector.size()-1);

    std::ifstream file(tmpFileName);
    std::string descriptionString;
    std::string descriptionNameString;
    if (file.is_open())
    {
        std::getline(file, descriptionString);
        std::getline(file, descriptionNameString);
        file.close();
    }

    MediaBuilder mediaBuilder;
    MediaDirector mediaDirector(&mediaBuilder);
    mediaDirector.construct(descriptionString);

    Media* media = mediaBuilder.getBaseShape();
    this->addToApplication(media, &descriptionNameString);
}

bool LoadCommand::checkValid(std::string command) {
    return CommandFunction::startWith(command, "load ");
}

void LoadCommand::addToApplication(Media *media, std::string *descriptionNameString) {
    CompositeMedia *compositeMedia = dynamic_cast<CompositeMedia*>(media);
    if(compositeMedia){
        unsigned long startIndex = descriptionNameString->find_first_of("{");
        std::string subString = descriptionNameString->substr(0, startIndex);
        *descriptionNameString = descriptionNameString->substr(startIndex+1);
        _application->addMedia(subString, media);
        for(unsigned int i=0; i<compositeMedia->size(); i++){
            this->addToApplication(compositeMedia->at(i), descriptionNameString);
        }
    }else{
        unsigned long startIndex = descriptionNameString->find_first_of(" ");
        std::string subString = descriptionNameString->substr(0, startIndex);
        *descriptionNameString = descriptionNameString->substr(startIndex+1);
        _application->addMedia(subString, media);
    }

}
