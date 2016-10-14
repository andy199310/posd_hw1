//
// Created by ChangChun-wei on 2016/10/7.
//

#ifndef POSD_HW1_MEDIA_H
#define POSD_HW1_MEDIA_H


#include "MediaVisitor.h"

class Media {
public:
    virtual void bbox() = 0;
    virtual void play() = 0;

    virtual void accept(MediaVisitor&) = 0;
};


#endif //POSD_HW1_MEDIA_H
