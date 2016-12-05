//
// Created by Green on 2016/12/5.
//

#include "Application.h"

bool Application::addMedia(std::string name, Media *media) {
    std::string *heapName = new std::string(name);
    if(this->getMediaByName(*heapName) == nullptr){
        _mediaMap.insert(std::pair<std::string,Media*>(name, media));
        return true;
    }else{
        return false;
    }
}

Media *Application::getMediaByName(std::string name) {
    if (_mediaMap.find(name) != _mediaMap.end())
        return _mediaMap.at(name);
    return nullptr;
}
