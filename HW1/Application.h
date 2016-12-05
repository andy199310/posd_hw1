//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_APPLICATION_H
#define POSD_HW1_APPLICATION_H


#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
#include "Media.h"

class Application {
private:
    std::map<std::string, Media*> _mediaMap;
    std::vector<std::string> _mediaNameVector;
    std::queue<std::string> _outputStringQueue;


public:
    bool addMedia(std::string name, Media* media);
    bool deleteMedia(std::string name);
    Media* getMediaByName(std::string name);
    void writeOutput(std::string message);
    std::string getNextOutputString();

public:
    std::map<std::string, Media*> getMediaMap();
    std::vector<std::string> getMediaNameVector();
};


#endif //POSD_HW1_APPLICATION_H
