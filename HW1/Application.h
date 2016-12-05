//
// Created by Green on 2016/12/5.
//

#ifndef POSD_HW1_APPLICATION_H
#define POSD_HW1_APPLICATION_H


#include <vector>
#include <map>
#include <string>
#include "Media.h"

class Application {
public:
    std::map<std::string, Media*> _mediaMap;


public:
    bool addMedia(std::string name, Media* media);
    Media* getMediaByName(std::string name);
};


#endif //POSD_HW1_APPLICATION_H
