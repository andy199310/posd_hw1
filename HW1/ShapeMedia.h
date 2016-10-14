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
    void add(Shape *shape);

    int size() const;

    virtual void accept(MediaVisitor *visitor) override;

private:
    std::vector<Shape *> shapeVector;
};


#endif //POSD_HW1_SHAPEMEDIA_H
