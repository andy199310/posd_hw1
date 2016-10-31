//
// Created by Green on 2016/10/28.
//

#ifndef POSD_HW1_MEDIABUILDER_H
#define POSD_HW1_MEDIABUILDER_H


#include <stack>
#include "Media.h"

class MediaBuilder {
private:
    std::stack<Media*> baseMediaStack;
public:
    MediaBuilder();

    virtual void levelDone();

    virtual void buildCompositeMedia();

    virtual void buildShapeMedia();

    virtual void buildRectangle(double x, double y, double width, double height);

    virtual void buildCircle(double centerX, double centerY, double radius);

    virtual void buildTriangle(double point1X, double point1Y, double point2X, double point2Y, double point3X, double point3Y);

    virtual Media* getBaseShape();
};


#endif //POSD_HW1_MEDIABUILDER_H
