//
// Created by ChangChun-wei on 2016/10/7.
//

#ifndef POSD_HW1_MEDIA_H
#define POSD_HW1_MEDIA_H

class MediaVisitor;

class Media {
public:

    virtual void add(Media *shape) = 0;

    virtual bool remove(Media *removeMedia) = 0;

    virtual void accept(MediaVisitor*) = 0;
};


#endif //POSD_HW1_MEDIA_H
