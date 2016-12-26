//
// Created by Green on 2016/12/5.
//

#include <iostream>
#include "../Execption/ArgumentMismatchException.h"
#include "../Execption/NameNotFoundException.h"
#include "DeleteCommand.h"
#include "CommandFunction.h"

DeleteCommand::DeleteCommand(Application *application):_application(application) {

}

void DeleteCommand::execute(std::string command) {
    _command = command;
    std::vector<std::string> argumentVector;
    CommandFunction::split(command, argumentVector, ' ');
    if(argumentVector.size() != 4 && argumentVector.size() != 2){
        throw ArgumentMismatchException();
    }

    if(argumentVector.size() == 2){
        Media *media = _application->getMediaByName(argumentVector.at(1));
        if(media == nullptr){
            throw NameNotFoundException(argumentVector.at(1));
        }
        _key = argumentVector.at(1);
        _deleteTarget = media;
        std::map<std::string, Media *> mediaMap = _application->getMediaMap();
        typedef std::map<std::string, Media*>::iterator it_type;
        for(it_type iterator = mediaMap.begin(); iterator != mediaMap.end(); iterator++) {
            if(iterator->second->haveChild(media)){
                _parentVector.push_back(iterator->first);
            };
        }
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
        _parentKey = argumentVector.at(3);
        _key = argumentVector.at(1);
        parent->remove(child);
    }
}

bool DeleteCommand::checkValid(std::string command) {
    return CommandFunction::startWith(command, "delete ");
}

bool DeleteCommand::needUndo() {
    return true;
}

void DeleteCommand::undo() {
    if(_parentKey.length() != 0){
        Media *parent = _application->getMediaByName(_parentKey);
        Media *child = _application->getMediaByName(_key);
        parent->add(child);
    }else{
        _application->addMedia(_key, _deleteTarget);
        for(std::string smallKey : _parentVector){
            Media *parent = _application->getMediaByName(smallKey);
            parent->add(_deleteTarget);
        }
    }
}

void DeleteCommand::redo() {
    this->execute(_command);
}

Command *DeleteCommand::clone() {
    return new DeleteCommand(_application);
}
