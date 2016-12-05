//
// Created by Green on 2016/12/5.
//

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
    return nullptr;
}

std::map<std::string, Media *> Application::getMediaMap() {
    return _mediaMap;
}

std::vector<std::string> Application::getMediaNameVector() {
    return _mediaNameVector;
}
