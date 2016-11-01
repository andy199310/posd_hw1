//
// Created by ChangChun-wei on 2016/10/7.
//

#ifndef POSD_HW1_SHAPEMEDIA_H
#define POSD_HW1_SHAPEMEDIA_H


#include <vector>
#include "Media.h"
#include "Shape.h"

class ShapeMedia : public Media{
public:
    ShapeMedia(Shape* shape);

    virtual void add(Media* media) override;

    virtual bool remove(Media *removeMedia) override;

    virtual Shape* getShape();

    virtual void accept(MediaVisitor *visitor) override;

private:
    Shape* _shape;
};


#endif //POSD_HW1_SHAPEMEDIA_H
