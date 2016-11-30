//
// Created by Green on 2016/11/21.
//

#include <iostream>
#include <sstream>
#include "MediaDirector.h"

MediaDirector::MediaDirector(MediaBuilder *mediaBuilder) {
    _mediaBuilder = mediaBuilder;
}

void MediaDirector::construct(std::string string) {
    while(string.length()){
        if(startWith(string, std::string("combo("))){
            _mediaBuilder->buildCompositeMedia();
            string = string.substr(6);
            continue;
        }
        if(startWith(string, std::string("r("))){
            unsigned long endIndex = string.find_first_of(")");
            std::string argumentString = string.substr(2, endIndex - 2);
            std::vector<double>* arguments = getArgumentFromString(argumentString, 4);

            _mediaBuilder->buildRectangle(arguments->at(0), arguments->at(1), arguments->at(2), arguments->at(3));

            string = string.substr(endIndex + 2);
            continue;
        }
        if(startWith(string, std::string("c("))){
            unsigned long endIndex = string.find_first_of(")");
            std::string argumentString = string.substr(2, endIndex - 2);
            std::vector<double>* arguments = getArgumentFromString(argumentString, 3);

            _mediaBuilder->buildCircle(arguments->at(0), arguments->at(1), arguments->at(2));

            string = string.substr(endIndex + 2);
            continue;
        }
        if(startWith(string, std::string("t("))){
            unsigned long endIndex = string.find_first_of(")");
            std::string argumentString = string.substr(2, endIndex - 2);
            std::vector<double>* arguments = getArgumentFromString(argumentString, 6);

            _mediaBuilder->buildTriangle(arguments->at(0), arguments->at(1), arguments->at(2), arguments->at(3), arguments->at(4), arguments->at(5));

            string = string.substr(endIndex + 2);
            continue;
        }


        if(startWith(string, std::string(")"))){
            _mediaBuilder->levelDone();
            string = string.substr(1);
            continue;
        }
    }
}

Media *MediaDirector::getResult() {
    return _mediaBuilder->getBaseShape();
}

std::vector<double>* MediaDirector::getArgumentFromString(std::string string, int expectedItem) {
    std::vector<double> *items = new std::vector<double>;
    double tmpDouble;
    std::stringstream stream(string);
    std::string tmpString;

    while(std::getline(stream, tmpString, ' ')){
        std::stringstream tmpStream(tmpString);
        tmpStream >> tmpDouble;
        items->push_back(tmpDouble);
    }

    return items;
}

bool MediaDirector::startWith(std::string origin, std::string key) {
    return origin.compare(0, key.length(), key) == 0;
}


