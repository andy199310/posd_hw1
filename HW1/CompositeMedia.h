//
// Created by Green on 2016/10/4.
//

#ifndef POSD_HW1_COMPOSITESHAPE_H
#define POSD_HW1_COMPOSITESHAPE_H


#include <vector>
#include "Shape.h"

class CompositeMedia : public Media{
public:
    CompositeMedia();

    void add(Media *shape);
    void remove(unsigned int index);
    int size() const;
    Media* at(unsigned int index) const;

    virtual void accept(MediaVisitor& visitor) override;

private:
    std::vector<Media *> mediaVector;

};


#endif //POSD_HW1_COMPOSITESHAPE_H
