//
// Created by Green on 2016/10/4.
//

#ifndef POSD_HW1_COMPOSITESHAPE_H
#define POSD_HW1_COMPOSITESHAPE_H


#include <vector>
#include "Shape.h"
class MediaVisitor;

class CompositeMedia : public Media{
public:
    CompositeMedia();

    void add(Media *shape) override;
    void remove(unsigned int index);

    virtual bool remove(Media *removeMedia) override;

    int size() const;
    Media* at(unsigned int index) const;

    virtual void accept(MediaVisitor* visitor) override;

private:
    std::vector<Media *> mediaVector;

};


#endif //POSD_HW1_COMPOSITESHAPE_H
