//
// Created by Green on 2016/11/21.
//

#ifndef POSD_HW1_MEDIADIRECTOR_H
#define POSD_HW1_MEDIADIRECTOR_H


#include <string>
#include <vector>
#include "MediaBuilder.h"

class MediaDirector {
private:
    MediaBuilder *_mediaBuilder;

public:
    MediaDirector(MediaBuilder *mediaBuilder);
    virtual void construct(std::string string);

    virtual Media* getResult();
private:
    virtual bool startWith(std::string origin, std::string key);
    virtual std::vector<double>* getArgumentFromString(std::string string, int expectedItem);
};


#endif //POSD_HW1_MEDIADIRECTOR_H
