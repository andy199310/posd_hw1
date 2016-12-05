//
// Created by Green on 2016/12/5.
//

#include "../Execption/ArgumentMismatchException.h"
#include "../Execption/NameNotFoundException.h"
#include "DeleteCommand.h"
#include "CommandFunction.h"

DeleteCommand::DeleteCommand(Application *application):_application(application) {

}

void DeleteCommand::execute(std::string command) {
    std::vector<std::string> argumentVector;
    CommandFunction::split(command, argumentVector, ' ');
    if(argumentVector.size() != 4 && argumentVector.size() != 2){
        throw ArgumentMismatchException();
    }

    if(argumentVector.size() == 2){
        Media *media = _application->getMediaByName(argumentVector.at(1));
        if(media == nullptr){
            throw NameNotFoundException(argumentVector.at(0));
        }
        std::map<std::string, Media *> mediaMap = _application->getMediaMap();
        //delete relation
        typedef std::map<std::string, Media*>::iterator it_type;
        for(it_type iterator = mediaMap.begin(); iterator != mediaMap.end(); iterator++) {
             iterator->second->remove(media);
        }
        //delete itself
        _application->deleteMedia(argumentVector.at(1));
    }else{
        Media *child = _application->getMediaByName(argumentVector.at(1));
        if(child == nullptr){
            throw NameNotFoundException(argumentVector.at(0));
        }
        Media *parent = _application->getMediaByName(argumentVector.at(3));
        if(parent == nullptr){
            throw NameNotFoundException(argumentVector.at(3));
        }
        parent->remove(child);
    }
}
