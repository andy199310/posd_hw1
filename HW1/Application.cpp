//
// Created by Green on 2016/12/5.
//

#include <cstdio>
#include "Application.h"

bool Application::addMedia(std::string name, Media *media) {
    std::string *heapName = new std::string(name);
    if(this->getMediaByName(*heapName) == nullptr){
        _mediaMap.insert(std::pair<std::string,Media*>(*heapName, media));
        _mediaNameVector.push_back(*heapName);
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

void Application::writeOutput(std::string message) {
    _outputStringQueue.push(message);
}

std::string Application::getNextOutputString() {
    if(_outputStringQueue.size() > 0){
        std::string returnString = _outputStringQueue.front();
        _outputStringQueue.pop();
        return returnString;
    }
    return std::string();
}

std::map<std::string, Media *> Application::getMediaMap() {
    return _mediaMap;
}

std::vector<std::string> Application::getMediaNameVector() {
    return _mediaNameVector;
}

bool Application::deleteMedia(std::string name) {
    if(this->getMediaByName(name) != nullptr){
        _mediaMap.erase(name);
        for(std::vector<std::string>::iterator iter = _mediaNameVector.begin(); iter != _mediaNameVector.end(); ++iter )
        {
            if( *iter == name )
            {
                _mediaNameVector.erase( iter );
                break;
            }
        }
        return true;
    }else{
        return false;
    }
}

std::string Application::getNameByMedia(Media *media) {
    for(std::map<std::string, Media*>::iterator iter = _mediaMap.begin(); iter != _mediaMap.end(); ++iter )
    {
        if(iter->second == media){
            return iter->first;
        }
    }
    return nullptr;
}
