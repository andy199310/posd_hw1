//
// Created by Green on 2016/12/5.
//

#include <iostream>
#include <sstream>
#include "CommandFunction.h"

unsigned int CommandFunction::split(const std::string &txt, std::vector<std::string> &strs, char ch) {
    unsigned int pos = txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos + 1 ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

void CommandFunction::printVector(const std::vector<std::string> &vector) {
    for(unsigned int i=0; i<vector.size(); i++){
        std::cout << i << " : " << vector.at(i) << std::endl;
    }
    std::cout << "==========" << std::endl;
}

bool CommandFunction::startWith(std::string origin, std::string key) {
    return origin.compare(0, key.length(), key) == 0;
}

void CommandFunction::getShapeArgumentFromString(std::vector<double> *argumentVector, std::string string) {
    unsigned long startIndex = string.find_first_of("(");
    unsigned long endIndex = string.find_first_of(")");
    std::string subString = string.substr(startIndex+1, endIndex-startIndex-1);

    double tmpDouble;
    std::stringstream stream(subString);
    std::string tmpString;

    while(std::getline(stream, tmpString, ',')){
        std::stringstream tmpStream(tmpString);
        tmpStream >> tmpDouble;
        argumentVector->push_back(tmpDouble);
    }
}

void CommandFunction::getComboArgumentFromString(std::vector<std::string> *argumentVector, std::string string) {
    unsigned long startIndex = string.find_first_of("{");
    unsigned long endIndex = string.find_first_of("}");
    std::string subString = string.substr(startIndex+1, endIndex-startIndex-1);

    double tmpDouble;
    std::stringstream stream(subString);
    std::string tmpString;

    while(std::getline(stream, tmpString, ',')){
        argumentVector->push_back(tmpString);
    }
}

